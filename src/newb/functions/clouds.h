#ifndef CLOUDS_H
#define CLOUDS_H

#include "noise.h"
#include "sky.h"

// simple clouds 2D noise
float cloudNoise2D(vec2 p, highp float t, float rain) {
  t *= NL_CLOUD1_SPEED;
  p += t;
  p.x += sin(p.y*0.4 + t);

  vec2 p0 = floor(p);
  vec2 u = p-p0;
  u *= u*(3.0-2.0*u);
  vec2 v = 1.0-u;

  // rain transition
  vec2 d = vec2(0.09+0.5*rain,0.089+0.5*rain*rain);

  return v.y*(randt(p0,d)*v.x + randt(p0+vec2(1.0,0.0),d)*u.x) +
         u.y*(randt(p0+vec2(0.0,1.0),d)*v.x + randt(p0+vec2(1.0,1.0),d)*u.x);
}

// simple clouds
vec4 renderCloudsSimple(nl_skycolor skycol, vec3 pos, highp float t, float rain) {
  pos.xz *= NL_CLOUD1_SCALE;

  float cloudAlpha = cloudNoise2D(pos.xz, t, rain);
  float cloudShadow = cloudNoise2D(pos.xz*0.91, t, rain);

  vec4 color = vec4(0.02,0.04,0.05,cloudAlpha);

  color.rgb += skycol.horizonEdge;
  color.rgb *= 1.0 - 0.5*cloudShadow*step(0.0, pos.y);

  color.rgb += skycol.zenith*0.7;
  color.rgb *= 1.0 - 0.4*rain;

  return color;
}

// rounded clouds

// rounded clouds 3D density map
float cloudDf(vec3 pos, float rain, float boxiness) {
  vec2 p0 = floor(pos.xz);
  vec2 u = smoothstep(0.999*boxiness, 1.0, pos.xz-p0);

  // rain transition
  vec2 t = vec2(0.1001+0.2*rain, 0.1+0.2*rain*rain);

  float n = mix(
    mix(randt(p0, t),randt(p0+vec2(1.0,0.0), t), u.x),
    mix(randt(p0+vec2(0.0,1.0), t),randt(p0+vec2(1.0,1.0), t), u.x),
    u.y
  );

  // round y
  float b = 1.0 - 1.9*smoothstep(boxiness, 2.0 - boxiness, 2.0*abs(pos.y-0.5));
  return smoothstep(0.2, 1.0, n * b);
}

vec4 renderClouds(
    vec3 vDir, vec3 vPos, float rain, float time, vec3 fogCol, vec3 skyCol,
    const int steps, const float thickness, const float thickness_rain, const float speed,
    const vec2 scale, const float density, const float boxiness
) {
  float height = 7.0*mix(thickness, thickness_rain, rain);
  float stepsf = float(steps);

  // scaled ray offset
  vec3 deltaP;
  deltaP.y = 1.0;
  deltaP.xz = height*scale*vDir.xz/(0.02+0.98*abs(vDir.y));
  //deltaP.xyz = (scale*height)*vDir.xyz;
  //deltaP.y = abs(deltaP.y);

  // local cloud pos
  vec3 pos;
  pos.y = 0.0;
  pos.xz = scale*(vPos.xz + vec2(1.0,0.5)*(time*speed));
  pos += deltaP;

  deltaP /= -stepsf;

  // alpha, gradient
  vec2 d = vec2(0.0,1.0);
  for (int i=1; i<=steps; i++) {
    float m = cloudDf(pos, rain, boxiness);

    d.x += m;
    d.y = mix(d.y, pos.y, m);

    //if (d.x == 0.0 && i > steps/2) {
    //	break;
    //} 

    pos += deltaP;
  }
  //d.x *= vDir.y*vDir.y; 
  d.x *= smoothstep(1.0, 1.0, d.x);
  d.x /= (stepsf/density) + d.x;

  if (vPos.y > 0.0) { // view from bottom
    d.y = 1.0 - d.y;
  }

  d.y = 1.0 - NL_CLOUD2_SHADOW_INTENSITY*d.y*d.y;

  float night = max(1.1 - 3.0*max(fogCol.b, fogCol.g), 0.0);
  
  vec4 col = vec4(0.3*skyCol, d.x);
  col.rgb += (skyCol + NL_CLOUD2_BRIGHTNESS*fogCol)*d.y;
  col.rgb *= 1.0 - 0.5*rain;
  col.rgb *= 1.0 - 0.8*night;
  
    #ifdef NL_NIGHT_CLOUD2_INTENSITY
    float op = col.a - d.y;
    op = col.a - d.x;
    
    op = NL_NIGHT_CLOUD2_INTENSITY;
    
    col.a *= op;
    #endif
    
  return col;
}

// aurora is rendered on clouds layer
#ifdef NL_AURORA
vec4 renderAurora(vec3 p, float t, float rain, vec3 FOG_COLOR) {
  t *= NL_AURORA_VELOCITY;
  p.xz *= NL_AURORA_SCALE;
  p.xz += 0.05*sin(p.x*4.0 + 20.0*t);

  float d0 = sin(p.x*0.1 + t + sin(p.z*0.2));
  float d1 = sin(p.z*0.1 - t + sin(p.x*0.2));
  float d2 = sin(p.z*0.1 + 1.0*sin(d0 + d1*2.0) + d1*2.0 + d0*1.0);
  d0 *= d0; d1 *= d1; d2 *= d2;
  d2 = d0/(1.0 + d2/NL_AURORA_WIDTH);

  float mask = (1.0-0.8*rain)*max(1.0 - 4.0*max(FOG_COLOR.b, FOG_COLOR.g), 0.0);
  return vec4(NL_AURORA*mix(NL_AURORA_COL1,NL_AURORA_COL2,d1),1.0)*d2*mask;
}
#endif

#endif
