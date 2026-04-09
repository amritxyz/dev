#include "main.h"
#include <raylib.h>

void
main_loop(Vector3 *position, Rotation *rotation, Camera3D camera)

{
	while (!WindowShouldClose()) { /* translate */
		if (IsKeyDown(KEY_W)) position->z -= 0.1f;
		if (IsKeyDown(KEY_S)) position->z += 0.1f;
		if (IsKeyDown(KEY_A)) position->x -= 0.1f;
		if (IsKeyDown(KEY_D)) position->x += 0.1f;
		if (IsKeyDown(KEY_Q)) position->y += 0.1f;
		if (IsKeyDown(KEY_E)) position->y -= 0.1f;

		/* rotate */
		if (IsKeyDown(KEY_K)) rotation->x += 0.9f;
		if (IsKeyDown(KEY_J)) rotation->x -= 0.9f;
		if (IsKeyDown(KEY_H)) rotation->y += 0.9f;
		if (IsKeyDown(KEY_L)) rotation->y -= 0.9f;
		if (IsKeyDown(KEY_N)) rotation->z += 0.9f;
		if (IsKeyDown(KEY_P)) rotation->z -= 0.9f;

		/* init_cube() with camera, position and rot_*(x, y, z) */
		init_cube(camera, *position, *rotation);
	}
}

void
init_cube(Camera3D camera, Vector3 position, Rotation rotation)
{
		BeginDrawing();
		ClearBackground(BLACK);

		SetTargetFPS(60);
		const char *fps = TextFormat("FPS: %d", GetFPS());
		DrawText(fps, 10, 80, 20, RED);

		BeginMode3D(camera);

		rlPushMatrix();

			/* Multiply the current matrix by a translation matrix */
			rlTranslatef(position.x, position.y, position.z);
			/* rlRotatef */
			/*[ rot_x 1  0  0 ]
			  [ rot_y 0  1  0 ]
			  [ rot_z 0  0  1 ] */
			rlRotatef(rotation.x, 1, 0, 0);
			rlRotatef(rotation.y, 0, 1, 0);
			rlRotatef(rotation.z, 0, 0, 1);

			DrawCube((Vector3){0,0,0}, 2.0f, 2.0f, 2.0f, RED);
			DrawCubeWires((Vector3){0,0,0}, 2.0f, 2.0f, 2.0f, BLACK);

		rlPopMatrix();

		DrawGrid(10, 1.0f);

		EndMode3D();

		DrawText("WASD + QE to move", 10, 10, 20, WHITE);
		DrawText("HJKL + NP to rotate", 10, 30, 20, WHITE);

		EndDrawing();

}

int main(void)
{

	/* Resizable window */
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	i32 screen_width  = GetScreenWidth();
	i32 screen_height = GetScreenHeight();

	InitWindow(screen_width, screen_height, "float_win");

	/* Camera | FOV */
	Camera3D camera  = { 0 };
	camera.position = (Vector3) {5.0f, 3.0f, 5.0f};
	camera.target = (Vector3) {0.0f, 0.0f, 0.0f};
	camera.up = (Vector3) {1.0f, 1.0f, 0.0f};
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	/* Cube's initial position */
	Vector3 position = { 0.0f, 0.0f, 0.0f };

	/* Rotation */
	Rotation rotation = {
		.x = 0.0f,
		.y = 0.0f,
		.z = 0.0f
	};

	main_loop(&position, &rotation, camera);

	CloseWindow();
	return 0;
}
