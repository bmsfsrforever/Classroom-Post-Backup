#define

#ifdef WINDOWS
#include <stdlib.h>
#endif
#include <sys/stat.h>
#include <gtk/gtk.h>

GtkWidget *onClientRadioButton;
GtkWidget *onServerRadioButton;
GtkWidget *serverDirectoryBox;
GtkWidget *directoryBox;
GtkWidget *indexBox;
GtkWidget *creatorBox;
GtkWidget *dateBox;
GtkWidget *textBox;
GtkTextBuffer *textBuffer;
GtkWidget *commentIndexBox;
GtkWidget *commentCreatorBox;
GtkWidget *commentDateBox;
GtkWidget *commentTextBox;
GtkTextBuffer *commentTextBuffer;

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  char file[256];
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(onClientRadioButton))) {
    #ifdef POSIX
    strcat(strcpy(file, getenv("HOME")), "/postbu");
    #endif
    #ifdef WINDOWS
    strcat(strcpy(file, getenv("USERPROFILE")), "\\postbu");
    #endif
  } else {
    strcpy(file, gtk_entry_get_text(GTK_ENTRY(serverDirectoryBox)));
  }
  char fileready[256];
  #ifdef POSIX
  strcat(strcpy(fileready, file), "/");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(fileready, file), "\\");
  #endif
  char directory[256];
  strcat(strcpy(directory, fileready), gtk_entry_get_text(GTK_ENTRY(directoryBox)));
  char directoryready[256];
  #ifdef POSIX
  strcat(strcpy(directoryready, directory), "/");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(directoryready, directory), "\\");
  #endif
  char index[256];
  strcat(strcpy(index, directoryready), gtk_entry_get_text(GTK_ENTRY(indexBox)));
  char creatorfile[256];
  #ifdef POSIX
  strcat(strcpy(creatorfile, index), "/creator.txt");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(creatorfile, index), "\\creator.txt");
  #endif
  char datefile[256];
  #ifdef POSIX
  strcat(strcpy(datefile, index), "/date.txt");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(datefile, index), "\\date.txt");
  #endif
  char textfile[256];
  #ifdef POSIX
  strcat(strcpy(textfile, index), "/text.txt");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(textfile, index), "\\text.txt");
  #endif
  #ifdef POSIX
  mkdir(file, S_IRWXU | S_IRWXG);
  mkdir(directory, S_IRWXU | S_IRWXG);
  mkdir(index, S_IRWXU | S_IRWXG);
  #endif
  #ifdef WINDOWS
  mkdir(file);
  mkdir(directory);
  mkdir(index);
  #endif
  g_print("It got this far\n");
  FILE *fp;
  g_print("FILE *fp\n");
  fp = fopen(creatorfile, "w");
  g_print("fopen\n");
  fprintf(fp, gtk_entry_get_text(GTK_ENTRY(creatorBox)));
  g_print("fprintf\n");
  fclose(fp);
  g_print("fclose\n");
  FILE *dfp;
  dfp = fopen(datefile, "w");
  fprintf(dfp, gtk_entry_get_text(GTK_ENTRY(dateBox)));
  fclose(dfp);
  g_print("Finished date\n");
  textBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textBox));
  GtkTextIter start;
  GtkTextIter end;
  gtk_text_buffer_get_start_iter(textBuffer, &start);
  gtk_text_buffer_get_end_iter(textBuffer, &end);
  gchar *text = gtk_text_buffer_get_text(textBuffer, &start, &end, TRUE);
  g_print("Got the text\n");
  g_file_set_contents(textfile, text, strlen(text), NULL);
  g_print("We made it!!!\n");
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(onServerRadioButton))) {
  g_print("On server\n");
  }
}

static void archive_comment(GtkWidget *widget, gpointer data) {
  char file[256]; //Get postbu directory
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(onClientRadioButton))) {
    #ifdef POSIX
    strcat(strcpy(file, getenv("HOME")), "/postbu");
    #endif
    #ifdef WINDOWS
    strcat(strcpy(file, getenv("USERPROFILE")), "\\postbu");
    #endif
  } else {
    strcpy(file, gtk_entry_get_text(GTK_ENTRY(serverDirectoryBox)));
  }
  char fileready[256]; //Append / to postbu directory
  #ifdef POSIX
  strcat(strcpy(fileready, file), "/");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(fileready, file), "\\");
  #endif
  char directory[256]; //Get class directory
  strcat(strcpy(directory, fileready), gtk_entry_get_text(GTK_ENTRY(directoryBox)));
  char directoryready[256]; //Append / to class directory
  #ifdef POSIX
  strcat(strcpy(directoryready, directory), "/");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(directoryready, directory), "\\");
  #endif
  char index[256]; //Get post directory
  strcat(strcpy(index, directoryready), gtk_entry_get_text(GTK_ENTRY(indexBox)));
  char indexready[256]; //Append / to post directory
  #ifdef POSIX
  strcat(strcpy(indexready, index), "/");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(indexready, index), "\\");
  #endif
  char commentdir[256]; //Get Comments directory
  strcat(strcpy(commentdir, indexready), "Comments");
  char commentdirready[256]; //Append / to Comments directory
  #ifdef POSIX
  strcat(strcpy(commentdirready, commentdir), "/");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(commentdirready, commentdir), "\\");
  #endif
  char commentindex[256]; //Get comment directory
  strcat(strcpy(commentindex, commentdirready), gtk_entry_get_text(GTK_ENTRY(commentIndexBox)));
  char commentcreatorfile[256]; //Get comment creator file
  #ifdef POSIX
  strcat(strcpy(commentcreatorfile, commentindex), "/creator.txt");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(commentcreatorfile, commentindex), "\\creator.txt");
  #endif
  char commentdatefile[256]; //Get comment date file
  #ifdef POSIX
  strcat(strcpy(commentdatefile, commentindex), "/date.txt");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(commentdatefile, commentindex), "\\date.txt");
  #endif
  char commenttextfile[256]; //Get comment text file
  #ifdef POSIX
  strcat(strcpy(commenttextfile, commentindex), "/text.txt");
  #endif
  #ifdef WINDOWS
  strcat(strcpy(commenttextfile, commentindex), "\\text.txt");
  #endif
  #ifdef POSIX
  mkdir(commentdir, S_IRWXU | S_IRWXG); //Create Comments directory
  mkdir(commentindex, S_IRWXU | S_IRWXG); //Create comment directory
  #endif
  #ifdef WINDOWS
  mkdir(commentdir);
  mkdir(commentindex);
  #endif
  FILE *cfp;
  cfp = fopen(commentcreatorfile, "w");
  fprintf(cfp, gtk_entry_get_text(GTK_ENTRY(commentCreatorBox)));
  fclose(cfp);
  FILE *cdfp;
  cdfp = fopen(commentdatefile, "w");
  fprintf(cdfp, gtk_entry_get_text(GTK_ENTRY(commentDateBox)));
  fclose(cdfp);
  commentTextBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(commentTextBox));
  GtkTextIter commentStart;
  GtkTextIter commentEnd;
  gtk_text_buffer_get_start_iter(commentTextBuffer, &commentStart);
  gtk_text_buffer_get_end_iter(commentTextBuffer, &commentEnd);
  gchar *commenttext = gtk_text_buffer_get_text(commentTextBuffer, &commentStart, &commentEnd, TRUE);
  g_file_set_contents(commenttextfile, commenttext, strlen(commenttext), NULL);
  g_print("Finished commenting.");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *grid;
  GtkWidget *button;
  GtkWidget *my_label;
  GtkWidget *commentButton;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Post Backup 2");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  grid = gtk_grid_new();
  gtk_container_add(GTK_CONTAINER(window), grid);

  onClientRadioButton = gtk_radio_button_new_with_label(NULL, "Client");
  gtk_grid_attach(GTK_GRID(grid), onClientRadioButton, 0, 0, 1, 1);
  onServerRadioButton = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(onClientRadioButton), "Server");
  gtk_grid_attach_next_to(GTK_GRID(grid), onServerRadioButton, onClientRadioButton, GTK_POS_BOTTOM, 1, 1);
  serverDirectoryBox = gtk_entry_new();
  gtk_entry_set_placeholder_text(GTK_ENTRY(serverDirectoryBox), "Backup location");
  gtk_grid_attach_next_to(GTK_GRID(grid), serverDirectoryBox, onServerRadioButton, GTK_POS_BOTTOM, 1, 1);
  directoryBox = gtk_entry_new();
  gtk_grid_attach_next_to(GTK_GRID(grid), directoryBox, serverDirectoryBox, GTK_POS_BOTTOM, 1, 1);
  indexBox = gtk_entry_new();
  gtk_grid_attach_next_to(GTK_GRID(grid), indexBox, directoryBox, GTK_POS_BOTTOM, 1, 1);
  creatorBox = gtk_entry_new();
  gtk_grid_attach_next_to(GTK_GRID(grid), creatorBox, indexBox, GTK_POS_BOTTOM, 1, 1);
  dateBox = gtk_entry_new();
  gtk_grid_attach_next_to(GTK_GRID(grid), dateBox, creatorBox, GTK_POS_BOTTOM, 1, 1);
  textBox = gtk_text_view_new();
  gtk_grid_attach_next_to(GTK_GRID(grid), textBox, dateBox, GTK_POS_BOTTOM, 1, 1);
  button = gtk_button_new_with_label ("Archive");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach_next_to(GTK_GRID(grid), button, textBox, GTK_POS_BOTTOM, 1, 1);
  my_label = gtk_label_new("Click above to archive post.");
  gtk_grid_attach_next_to(GTK_GRID(grid), my_label, button, GTK_POS_BOTTOM, 1, 1);
  commentIndexBox = gtk_entry_new();
  gtk_grid_attach_next_to(GTK_GRID(grid), commentIndexBox, my_label, GTK_POS_BOTTOM, 1, 1);
  commentCreatorBox = gtk_entry_new();
  gtk_grid_attach_next_to(GTK_GRID(grid), commentCreatorBox, commentIndexBox, GTK_POS_BOTTOM, 1, 1);
  commentDateBox = gtk_entry_new();
  gtk_grid_attach_next_to(GTK_GRID(grid), commentDateBox, commentCreatorBox, GTK_POS_BOTTOM, 1, 1);
  commentTextBox = gtk_text_view_new();
  gtk_grid_attach_next_to(GTK_GRID(grid), commentTextBox, commentDateBox, GTK_POS_BOTTOM, 1, 1);
  commentButton = gtk_button_new_with_label("Comment");
  g_signal_connect(commentButton, "clicked", G_CALLBACK(archive_comment), NULL);
  gtk_grid_attach_next_to(GTK_GRID(grid), commentButton, commentTextBox, GTK_POS_BOTTOM, 1, 1);

  gtk_widget_show_all (window);
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
