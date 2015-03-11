/*
 * main.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: root
 */


#include <iostream>
#include <cstdlib>
#include <gtk/gtk.h>

#include <log/AssistorLog.h>

using namespace std;

void hello(GtkWidget *widget, gpointer data)
{
	g_print("HELLO,WORLD\n");
}

int main(int argc, char **argv)
{
	AssistorLog::init_log_system(AssistorLog::FILE,
			Log::INFO,
			"assistor.log", ios_base::trunc);

	AssistorLog::log("main", Log::INFO, "assistor start\n");

	GtkWidget *window;

	GtkWidget *button;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	button  = gtk_button_new_with_label("yes");

	g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(hello), NULL);
	gtk_container_set_border_width(GTK_CONTAINER(window), 20);
	gtk_container_add(GTK_CONTAINER(window), button);
	gtk_widget_show(button);
	gtk_widget_show(window);
	gtk_main();

	return 0;
}


