#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
int main(int argc, char **argv) {
  //opretter vindu
  Fl_Window *window = new Fl_Window(340,180);
  //legger til bx
  Fl_Box *box = new Fl_Box(40,40,300,100," Hello, World! ");

//box dettings
  box->box(FL_UP_BOX);
  box->labelfont(FL_BOLD+FL_ITALIC);
  box->labelsize(60);
  box->labeltype(FL_SHADOW_LABEL);

//skal ikke legge til fler, derfior -> end
  window->end();

  //vis vindu, enter fltk loop. 
  window->show(argc, argv);
  return Fl::run();
}


// #include <iostream>
// #include <FL/Fl.H>
// #include <FL/Fl_Window.H>
// #include <FL/Fl_Box.H>

// //Funksjoner for tegning
// #include <FL/fl_draw.H>


// // Vi lager en subklasse av Fl_box - den enkleste "widgeten".
// class dotbox : public Fl_Box {
//   int x = 180;
// public:
//   using Fl_Box::Fl_Box; //Arve konstruktører fra base (C++11)
  
//   void draw() override{ //Override draw fra box ('override' er C++11)   

//     //Tegnefunksjonene forutsetter #include <FL/fl_draw.H> og at man er "inni en Widget"
//     fl_color(FL_RED); //Sette penselfarge
//     fl_pie(160,80,30,30,0,360); //Tegne

//     fl_color(FL_GREEN); //...gjenta
//     fl_pie(170,90,40,40,0,360);

//     fl_color(FL_BLUE);
//     fl_pie(x++,100,30,30,0,360);
//   }
// };

// using namespace std;


// double interval = 0.1;


// void myCallback(void* widget){
//   Fl::repeat_timeout(interval,myCallback, widget);
//   cout << "Timeout!" << endl;
//   ((Fl_Window*)widget)->redraw();
// }

// using namespace std;

// int main(int argc, char** argv){
//   // Opprett et vindu
//   Fl_Window* window=new Fl_Window{340,180, "Dots!"};
  
//   // Opprette en instans av dotbox
//   dotbox *box=new dotbox{0,0,340,180};
//   dotbox *box2=new dotbox{170,90,340,180};

  
//   Fl::add_timeout(interval,myCallback, window);
  
//   // Sperr vinduet for å ta inn flere widgets
//   window->end();

//   // Vis vinduet
//   window->show();
  
//   // Start FLTK's event-loop (kjør appen)
//   Fl::run();
  
//   // 
//   delete box;
//   // ...vi brukte jo "new".
//   delete window;

// }
