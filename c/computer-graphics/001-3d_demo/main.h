#ifndef MAIN_H
#define MAIN_H

#include <raylib.h>
#include <rlgl.h>

#include <stdint.h>

/* Helper types */
typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t  b8;
typedef int32_t b32;
typedef float   f32;
typedef double  f64;

typedef struct {
	f32 x;
	f32 y;
	f32 z;
} Rotation;

void main_loop(Vector3 *, Rotation *, Camera3D);
void init_cube(Camera3D, Vector3, Rotation);

#endif /* MAIN_H */
