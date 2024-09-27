#include <gtk/gtk.h>

static void do_drawing(cairo_t *cr) {
    // Set the color for the rectangle (red)
    cairo_set_source_rgb(cr, 1, 0, 0); // Red color

    // Draw a rectangle
    cairo_rectangle(cr, 100, 100, 200, 100); // x, y, width, height
    cairo_fill(cr); // Fill the rectangle
}

static void on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    do_drawing(cr);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *drawing_area;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Rectangle Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Connect the destroy event to gtk_main_quit
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a drawing area
    drawing_area = gtk_drawing_area_new();
    gtk_container_add(GTK_CONTAINER(window), drawing_area);

    // Connect the draw event to the drawing function
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event), NULL);

    // Show all widgets in the window
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}

