#include <stdio.h>
#include <stdbool.h>

#define SOLID 0
#define DOTTED 1
#define DASHED 2

#define BLUE 4
#define GREEN 2
#define RED 1


#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white" };

struct box {
  bool opaque:1;
  unsigned int fill_color:3;
  unsigned int :4;
  bool show_border:1;
  unsigned int border_color:3;
  unsigned int border_style:2;
  unsigned int :2;
};

void display(struct box input_box) {
  input_box.opaque ?  printf("Box is opaque.\n") : printf("Box is transparent.\n");
  switch (input_box.fill_color) {
    case 7:
      printf("The fill color is white.\n");
      break;
    case 6:
      printf("The fill color is cyan.\n");
      break;
    case 5:
      printf("The fill color is magenta.\n");
      break;
    case 4:
      printf("The fill color is blue.\n");
      break;
    case 3:
      printf("The fill color is yellow.\n");
      break;
    case 2:
      printf("The fill color is green.\n");
      break;
    case 1:
      printf("The fill color is red.\n");
      break;
    case 0:
      printf("The fill color is black.\n");
      break;
  }
  input_box.show_border ?  printf("Border shown.\n") : printf("Box is not shown.\n");
  switch (input_box.border_color) {
    case 7:
      printf("The border color is white.\n");
      break;
    case 6:
      printf("The border color is cyan.\n");
      break;
    case 5:
      printf("The border color is magenta.\n");
      break;
    case 4:
      printf("The border color is blue.\n");
      break;
    case 3:
      printf("The border color is yellow.\n");
      break;
    case 2:
      printf("The border color is green.\n");
      break;
    case 1:
      printf("The border color is red.\n");
      break;
    case 0:
      printf("The border color is black.\n");
      break;
  }
  switch (input_box.border_style) {
      case 2:
        printf("The border style is dashed.\n");
        break;
      case 1:
        printf("The border style is dotted.\n");
        break;
      case 0:
        printf("The border style is solid.\n");
        break;
  }
}

int main_old() {
  struct box my_box = {1, 1, 3, 2, 2};
  printf("Original box settings: \n");
  display(my_box);
  my_box.opaque = 0;
  my_box.fill_color = 7;
  my_box.border_color = 5;
  my_box.border_style = 0;
  printf("\n\nModified box settings: \n");
  display(my_box);

  printf("%ld\n", sizeof(my_box));
  return 0;
}

void show_settings(const struct box *pb);

int main() {
  struct box my_box = { true, YELLOW, true, GREEN, DASHED };
  printf("Original box settings:\n");
  show_settings(&my_box);

  my_box.opaque = false;
  my_box.fill_color = WHITE;
  my_box.border_color = MAGENTA;
  my_box.border_style = SOLID;
  printf("\nChanged box settings:\n");
  show_settings(&my_box);
  return 0;
}

void show_settings(const struct box *pb) {
  printf("Box is %s.\n", pb->opaque == true ? "opaque" : "transparent");
  printf("The fill color is %s.\n", colors[pb->fill_color]);
  printf("Border %s.\n", pb->show_border == true ? "shown" : "not shown");
  printf("The border color is %s.\n", colors[pb->border_color]);
  printf("The border style is ");

  switch(pb->border_style) {
    case SOLID : printf("solid.\n"); break;
    case DOTTED : printf("dotted.\n"); break;
    case DASHED : printf("dashed.\n"); break;
    default    : printf("unknown type.\n");
  }
}
