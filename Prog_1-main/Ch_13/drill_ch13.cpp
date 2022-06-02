#include "../source/Simple_window.h"
#include "../source/Graph.h"

int main()
{
    try {
    Point tl(300,50);
    Simple_window win(tl,1000,800,"My window");
    win.wait_for_button();
    win.set_label("My window");
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

  
    Image akep1(Point(200,0),"palank.jpg");
    //akep1.set_mask(Point(200,0),200,200);
    win.attach(akep1);
    Image akep2(Point(500,200),"palank.jpg");
    //akep2.set_mask(Point(200,0),200,200);
    win.attach(akep2);
    Image akep3(Point(100,500),"palank.jpg");
    //akep3.set_mask(Point(200,0),200,200);
    win.attach(akep3);
    
    win.wait_for_button();
    Image akep(Point(0,0),"kosarlabda.jpg");
    //akep.set_mask(Point(110,70),100,100);
    win.attach(akep);
    
    win.wait_for_button();
    int counter = 0;
    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    
    while (counter < 10) {
        x = randint(8);
        y = randint(8);
        dx = 100*x - akep.point(0).x;
        dy = 100*y - akep.point(0).y;
        akep.move(dx,dy);
        counter = counter + 1;
        win.wait_for_button();
       
        
    }
}
catch (exception& e) {
    cerr << "Hiba: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "Hiba\n";
    keep_window_open();
}
    
}