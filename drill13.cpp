#include "Simple_window.h"
#include "Graph.h"
int main()
{
try {

    Point tl(300,50);
    Simple_window win(tl,1000,800,"window");
    win.wait_for_button();
    win.set_label("window");

    Lines grid;
    int x_size = 800;
    int y_size = 800;
    for (int i = 100; i<=x_size; i+=100) {
        grid.add(Point(i,0),Point(i,y_size));
        grid.add(Point(0,i),Point(x_size,i));
    }
    win.attach(grid);
    win.wait_for_button();
    Vector_ref<Graph_lib::Rectangle> vr;
    for (int i = 0; i<8; ++i) {
        vr.push_back(new Graph_lib::Rectangle(Point(i*100,i*100),101,101));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
    }
   
    win.wait_for_button();

    
    Image kep1(Point(200,0),"lo.jpg");
    kep1.set_mask(Point(200,0),200,200);
    win.attach(kep1);
    Image kep2(Point(500,200),"lo.jpg");
    kep2.set_mask(Point(200,0),200,200);
    win.attach(kep2);
    Image kep3(Point(100,500),"lo.jpg");
    kep3.set_mask(Point(200,0),200,200);
    win.attach(kep3);
    win.wait_for_button();

   
    Image kep4(Point(0,0),"lo.jpg");
    kep4.set_mask(Point(110,70),100,100);
    win.attach(kep4);
    win.wait_for_button();

    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    while (true) {
        x = randint(8);
        y = randint(8);
        dx = 100*x - kep4.point(0).x;
        dy = 100*y - kep4.point(0).y;
        kep4.move(dx,dy);
        win.wait_for_button();
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
}
