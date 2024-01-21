#ifndef NL_CONFIG_H
#define NL_CONFIG_H
// line 3 reserved

/*
  EDITING CONFIG:

  > TOGGLES
  if [toggle] is mentioned, then
  options can be commented to disable (by adding/removing '//')
  eg: #define PLANTS_WAVE    -> this is ON
      //#define PLANTS_WAVE  -> this is OFF

  > COLOR VALUES
  color format: vec3(<red>,<green>,<blue>)
  1.0 means 100%, 0.0 means 0%
  eg. vec3(1.0,1.0,0.0) = yellow

  > VALUES
  values must be decimal
  eg. 32 is wrong, 32.0 is correct

  > TYPES
  should be integer. options to choose will be mentioned there
  eg: #define NL_FOG_TYPE 2

  BUILD THE SHADER AFTER EACH EDIT
*/


/* -------- CONFIG STARTS HERE ----------- */

/* Color correction */
#define NL_TONEMAP_TYPE 3   // 1:Exponential, 2:Reinhard, 3:Extended Reinhard, 4:ACES
#define NL_CONSTRAST 0.75   // 0.3 low ~ 2.0 high
#define NL_EXPOSURE 1.7   // [toggle] 0.5 dark ~ 3.0 bright
//#define NL_SATURATION 1.1 // [toggle] 0.0 grayscale ~ 4.0 super saturated
//#define NL_TINT vec3(1.0,0.75,0.5) // [toggle] color overlay

/* Terrain lighting */
#define NL_SUN_INTENSITY 2.95   // 0.5 weak ~ 5.0 bright
#define NL_TORCH_INTENSITY 0.51  // 0.5 weak ~ 3.0 bright
#define NL_NIGHT_BRIGHTNESS 0.040 // 0.0 dark ~ 2.0 bright
#define NL_CAVE_BRIGHTNESS  0.18 // 0.0 dark ~ 2.0 bright
#define NL_SHADOW_INTENSITY 0.94 // 0.0 no shadow ~ 1.0 strong shadow
//#define NL_BLINKING_TORCH     // [toggle] flickering light
//#define NL_CLOUD_SHADOW       // [toggle] cloud shadow (simple clouds only)

/* Sun/moon light color on terrain */
#define NL_MORNING_SUN_COL vec3(1.0,0.45,0.14)
#define NL_NOON_SUN_COL    vec3(1.0,0.75,0.57)
#define NL_NIGHT_SUN_COL   vec3(0.5,0.64,1.00)

/* Torch colors */
#define NL_OVERWORLD_TORCH_COL  vec3(1.0,0.52,0.18)
#define NL_UNDERWATER_TORCH_COL vec3(1.0,0.52,0.18)
#define NL_NETHER_TORCH_COL     vec3(1.0,0.52,0.18)
#define NL_END_TORCH_COL        vec3(1.0,0.52,0.18)

/* Fog */
#define NL_FOG_TYPE 2        // 0:no fog, 1:vanilla, 2:smoother vanilla
#define NL_MIST_DENSITY 0.24 // 0.0 no mist ~ 1.0 misty

/* Sky colors - zenith=top, horizon=bottom */
#define NL_DAY_ZENITH_COL    vec3(0.0,0.186,0.565)
#define NL_DAY_HORIZON_COL   vec3(0.53,0.83,0.93)
#define NL_NIGHT_ZENITH_COL  vec3(0.008,0.035,0.09)
#define NL_NIGHT_HORIZON_COL vec3(0.002,0.118,0.220)
#define NL_RAIN_ZENITH_COL   vec3(0.85,0.9,1.0)
#define NL_RAIN_HORIZON_COL  vec3(1.0,1.0,1.0)
#define NL_END_ZENITH_COL    vec3(0.08,0.001,0.1)
#define NL_END_HORIZON_COL   vec3(0.28,0.031,0.33)
#define NL_DAWN_HORIZON_COL  vec3(1.0,0.4,0.3)
#define NL_DAWN_EDGE_COL     vec3(1.0,0.4,0.2)

/* Ore glow intensity */
#define NL_GLOW_TEX 5.0 // 0.4 weak ~ 8.0 bright

/* Waving */
#define NL_PLANTS_WAVE 0.05    // [toggle] 0.02 gentle ~ 0.4 violent
#define NL_LANTERN_WAVE 0.16   // [toggle] 0.05 subtle ~ 0.4 large swing
#define NL_WAVE_SPEED 3.1      // 0.5 slow wave ~ 5.0 very fast wave
//#define NL_EXTRA_PLANTS_WAVE // [toggle] !dont use! wave using texture coords (1.20.40 vanilla)

/* Water */
#define NL_WATER_TRANSPARENCY 0.95 // 0.0 transparent ~ 1.0 normal
#define NL_WATER_BUMP 0.02        // 0.001 plain ~ 0.2 bumpy water
#define NL_WATER_TEX_OPACITY 3.15  // 0.0 plain water ~ 1.0 vanilla water texture
#define NL_WATER_WAVE             // [toggle] wave effect
//#define NL_WATER_FOG_FADE         // [toggle] fog fade for water
#define NL_WATER_CLOUD_REFLECTION // [toggle] simple clouds/aurora reflection
#define NL_WATER_TINT vec3(0.914,0.929,0.961)

/* Underwater */
#define NL_UNDERWATER_BRIGHTNESS 0.8 // 0.0 dark ~ 3.0 bright
#define NL_CAUSTIC_INTENSITY 1.9     // 0.5 weak ~ 5.0 bright
#define NL_UNDERWATER_WAVE 0.1       // [toggle] 0.02 subtle ~ 0.6 trippy
#define NL_UNDERWATER_TINT vec3(0.9,1.0,0.9)

/* Cloud type */
#define NL_CLOUD_TYPE 2 // 0:vanilla, 1:soft, 2:rounded

/* Vanilla cloud settings - make sure to remove clouds.png when using this */
#define NL_CLOUD0_THICKNESS 2.0      // 0.5 slim ~ 8.0 fat
#define NL_CLOUD0_RAIN_THICKNESS 4.0 // 0.5 slim ~ 8.0 fat

/* Soft cloud settings */
#define NL_CLOUD1_SCALE vec2(0.016, 0.022) // 0.003 large ~ 0.2 tiny
#define NL_CLOUD1_DEPTH 1.3                // 0.0 no bump ~ 10.0 large bumps
#define NL_CLOUD1_SPEED 0.04               // 0.0 static ~ 0.4 fast moving
#define NL_CLOUD1_DENSITY 0.54             // 0.1 less clouds ~ 0.8 more clouds
#define NL_CLOUD1_OPACITY 0.9              // 0.0 invisible ~ 1.0 opaque

/* Rounded cloud Settings */
#define NL_CLOUD2_THICKNESS 2.2      // 0.5 slim ~ 5.0 fat
#define NL_CLOUD2_RAIN_THICKNESS 2.5 // 0.5 slim ~ 5.0 fat
#define NL_CLOUD2_STEPS 8            // 3 low quality ~ 16 high quality
#define NL_CLOUD2_SCALE 0.036        // 0.003 large ~ 0.3 tiny
#define NL_CLOUD2_SHAPE 0.68         // 0.0 round ~ 1.0 box
#define NL_CLOUD2_DENSITY 7.8        // 1.0 blurry ~ 100.0 sharp
#define NL_CLOUD2_VELOCIY 0.8        // 0.0 static ~ 4.0 very fast
//#define NL_CLOUD2_MULTILAYER       // [toggle] extra cloud layer

/*️ Aurora settings */
//#define NL_AURORA 3.0           // [toggle] 0.4 dim ~ 4.0 very bright
#define NL_AURORA_VELOCITY 0.03 // 0.0 static ~ 0.3 very fast
#define NL_AURORA_SCALE 0.04    // 0.002 large ~ 0.4 tiny
#define NL_AURORA_WIDTH 0.18    // 0.04 thin line ~ 0.4 thick lines
#define NL_AURORA_COL1 vec3(0.1,1.0,0.0)
#define NL_AURORA_COL2 vec3(0.0,0.66,1.0)

/* Rain effects */
#define NL_RAIN_MIST_OPACITY 0.12 // [toggle] 0.04 very subtle ~ 0.5 thick mist blow
#define NL_RAIN_WETNESS 0.5       // 0.0 no wetness - 1.0 fully wet blocks
#define NL_RAIN_PUDDLES 1.86       // 0.0 no puddles - 1.0 puddles

/* Chunk loading slide in animation */
//#define NL_CHUNK_LOAD_ANIM 100.0 // [toggle] -600.0 fall from top ~ 600.0 rise from bottom

/* Sun/Moon */
//#define NL_SUNMOON_ANGLE 45.0 // [toggle] 0.0 no tilt - 90.0 tilt of 90 degrees
#define NL_SUNMOON_SIZE 1.42     // 0.3 tiny - 4.0 massive

/* -------- CONFIG ENDS HERE ----------- */


/* these are config of different subpacks. dont change! */
/* names in pack.sh */

#ifdef LOW
  #undef NL_PLANTS_WAVE
  #undef NL_LANTERN_WAVE
  #undef NL_UNDERWATER_WAVE
  #undef NL_WATER_WAVE
  #undef NL_RAIN_MIST_OPACITY
  #undef NL_CLOUD_TYPE
  #define NL_CLOUD_TYPE 0
  #undef NL_FOG_TYPE
  #define NL_FOG_TYPE 0
#endif

#ifdef MEDIUM
  #undef NL_CLOUD_TYPE 
  #define NL_CLOUD_TYPE 1
  #define NL_CLOUD_SHADOW
  #define NL_AURORA 3.1
#endif

#ifdef HIGH
  #define NL_CHUNK_LOAD_ANIM 100.0
  #define NL_CLOUD2_MULTILAYER
  #define NL_EXTRA_PLANTS_WAVE
  #define NL_AURORA 3.0
#endif

#ifdef COMP_AURORA
  #define NL_EXPOSURE 1.7
  #define NL_SATURATION 1.1
  #define NL_GLOW_TEX 5.0
  #define NL_PLANTS_WAVE 0.05
  #define NL_EXTRA_PLANTS_WAVE
  #define NL_AURORA 3.0
#endif

#ifdef COMP_STYLE
  #define NL_EXPOSURE 1.7
  #define NL_SATURATION 1.1
  #define NL_GLOW_TEX 5.0
  #define NL_PLANTS_WAVE 0.05
  #define NL_EXTRA_PLANTS_WAVE
  #undef NL_AURORA 3.0
#endif

#ifdef CUSTOM
  #define NL_EXPOSURE 1.7
  #define NL_CLOUD2_MULTILAYER
  #define NL_AURORA 3.1
  #define NL_CHUNK_LOAD_ANIM 100.0
#endif

#ifdef DOUBLE_CLOUD_AURORA
  #define NL_CLOUD2_MULTILAYER
  #define NL_AURORA 3.0
  #define NL_BLINKING_TORCH
#endif

#ifdef DOUBLE_CLOUD
  #define NL_CLOUD2_MULTILAYER
  #undef NL_AURORA 3.0
#endif

#ifdef AURORA
  #undef NL_CLOUD2_MULTILAYER
  #define NL_AURORA 3.0
  #define NL_BLINKING_TORCH
#endif

#ifdef DEFAULT
  #undef NL_CLOUD_TYPE
  #define NL_CLOUD_TYPE 2
  #undef NL_AURORA 3.0
#endif

#endif