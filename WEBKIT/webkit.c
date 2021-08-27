/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

gboolean closeWebViewCb(WebKitWebView *webView,GtkWidget *window)
{
	gtk_widget_destroy(window);
	return TRUE;
}


int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);
	GtkWidget *main_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(main_window),800,600);
	WebKitWebView *webView=WEBKIT_WEB_VIEW(webkit_web_view_new());
	gtk_container_add(GTK_CONTAINER(main_window),GTK_WIDGET(webView));
	g_signal_connect(main_window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(webView,"close",G_CALLBACK(closeWebViewCb),gtk_main_quit);
	webkit_web_view_load_uri(webView,"http://www.example.com/");
	gtk_widget_grab_focus(GTK_WIDGET(webView));
	gtk_widget_show_all(main_window);
	gtk_main();

	return(TRUE);
}
