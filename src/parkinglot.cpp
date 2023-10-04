#include "parkinglot.h"
#include "figure.h"
using namespace std;

void pole::iscar()
{
    if (((this->angle) < (PI / 2)))
    {
        this->angle = this->angle + 0.03;
    }
}
void pole::out()
{
    if ((this->angle) > 0)
    {
        this->angle = this->angle - 0.04;
    }
}

void Parkinglot::draw()
{

    // ((Vehicles*)(s->Singleton_figures))->enter();
    entrance1.draw();
    // a.draw();
    for (int i = 0; i < stall_num; i++)
    {
        up[i].draw();
        down[i].draw();
    }
    for (int i = 0; i < stall_num; i++)
    {
        if (nteles[i] == 1)
        {
            teles[i + stall_num].draw();
        }
        if (nteles[i] == 0)
        {
            teles[i].draw();
        }
    }
    fream();
}

void Parkinglot::getstallstate()
{
    for (int i = 0; i < stall_num; i++)
    {
        cout << down[i].empty() << endl;
    }
}
Parkinglot::Parkinglot(double x, double y)
{
    anc = Vec(x, y); 
    do// ask user for the number of the stall
    {
        cout << "input an even num of stall(a number larger than 24 is recommended or the drawing will be strange): ";
        cin >> stall_num;
    } while (stall_num % 2 != 0);
    stall_num /= 2;
    up = new stall[stall_num];
    down = new stall[stall_num];
    gate_width = 3;//set the size of the parkinglot
    gate_length = 1;
    road_width = 2.5;
    stall_length = 4;
    stall_width = 1.5;
    Vec goup(0, stall_length + 2 * road_width);
    Vec loc_up = goup + anc;
    Vec right(stall_width, 0);
    nteles = new int[stall_num];

    for (int i = 0; i < stall_num; i++)
    {
        nteles[i] = rand() % 5;
    }
    for (int i = 0; i < stall_num * 2; i++)
    {
        tel temp;
        temp.set(Vec(-2, -2), 0, .5, .5, .5);
        teles.push_back(temp);
    }
    for (int i = 0; i < stall_num; i++)//set the anchor of each stall
    {
        Vec up_temp = right * i + loc_up;
        up[i].stall_locate(up_temp);
        up[i].stall_length(stall_length);
        up[i].stall_width(stall_width);

        Vec down_temp = right * i + anc;
        down[i].stall_locate(down_temp);
        down[i].stall_length(stall_length);
        down[i].stall_width(stall_width);
    }

    entrance1.set(anc, gate_width, gate_length);
    zoom(1.0 / stall_num);

    move(Vec(-.97 + gate_width, -stall_length - road_width));
    for (int i = 0; i < stall_num; i++)
    {
        if (nteles[i] == 1)
        {
            up[i].enter();
            teles[i + stall_num].set(up[i].getlocate(), .7 / stall_num, (float).5, (float).5, (float).5);
        }
        if (nteles[i] == 0)
        {
            down[i].enter();
            teles[i].set(down[i].getlocate(), .7 / stall_num, (float).5, (float).5, (float).5);
        }
    }
    // getstallstate();
}
int Parkinglot::emptynum()
{
    int cnt=0;
    for (int i=0;i<stall_num;i++)
    {
        if (nteles[i]==1||nteles[i]==0)
        {
            cnt++;
        }
    }
    cnt=stall_num*2-cnt;
    return cnt;
}
void Parkinglot::iscar()
{
    entrance1.iscar();
}
void extrance::iscar()
{
    pole1.iscar();
}
void Parkinglot::out()
{
    entrance1.out();
}
void extrance::out()
{
    pole1.out();
}
void Parkinglot::pole_draw()
{
    entrance1.pole_draw();
}
void extrance::pole_draw()
{
    pole1.pole_draw();
}

void pole::zoom(double k, Vec anc)
{
    Pole_locate = (Pole_locate + (anc * (-1.0))) * k + anc;
    pole_length *= k;
}

void pole::move(Vec dir)
{
    Pole_locate = Pole_locate + dir;
}
void stall::zoom(double k, Vec a)
{
    anc = (anc + (a * (-1.0))) * k + a;
    width *= k;
    length *= k;
}
void stall::move(Vec dir)
{
    anc = anc + dir;
}
void extrance::zoom(double k, Vec anc)
{
    gate1.zoom(k, anc);
    pole1.zoom(k, anc);
}
void extrance::move(Vec dir)
{
    gate1.move(dir);
    pole1.move(dir);
}
void Parkinglot::zoom(double k)
{
    entrance1.zoom(k, anc);
    gate_width *= k;
    road_width *= k;
    stall_length *= k;
    stall_width *= k;
    for (int i = 0; i < stall_num; i++)
    {
        up[i].zoom(k, anc);
        teles[i].zoom(k, anc);
    }
    for (int i = 0; i < stall_num; i++)
    {
        down[i].zoom(k, anc);
        teles[i + stall_num].zoom(k, anc);
    }
    /*
    for(int i=0;i<vecnum;i++)
    {
        Vehicles[i]->zoom(1.0/stall_num);
    }
    */
}
void Parkinglot::move(Vec dir)
{
    entrance1.move(dir);
    anc = anc + dir;
    for (int i = 0; i < stall_num; i++)
    {
        up[i].move(dir);
    }
    for (int i = 0; i < stall_num; i++)
    {
        down[i].move(dir);
    }
}
void gate::zoom(double k, Vec anc)
{
    gate_locate = (gate_locate + (anc * (-1.0))) * k + anc;
    width *= k;
    gate_length *= k;
}
void gate::move(Vec dir)
{
    gate_locate = gate_locate + dir;
}

void stall::enter()
{
    state = 0;
}

Vec Parkinglot::find()
{
    for (int i = 0; i < stall_num; i++)
    {
        if (down[i].empty())
        {
            down[i].enter();
            return down[i].getlocate();
        }
    }
    for (int i = 0; i < stall_num; i++)
    {
        if (up[i].empty())
        {
            up[i].enter();
            return up[i].getlocate();
        }
    }
    return Vec(-1,-1);
}
Parkinglot::~Parkinglot()
{
    delete[] up;
    delete[] down;
    delete[] nteles;
}
int Parkinglot::getstallnum() { return stall_num; }
line::line() = default;
void line::line_(Vec a, Vec b)
{
    line::a = a;
    line::b = b;
    // cout<<"a: ";a.print();cout<<"b: ";b.print();test
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2d(a.getX() * ZOOM, a.getY() * ZOOM);
    glVertex2d(b.getX() * ZOOM, b.getY() * ZOOM);
    glEnd();
}
line::~line() = default;
stall::stall() { state = 1; }
void stall::stall_locate(Vec pt) { stall::anc = pt; }
void stall::stall_length(double l) { stall::length = l; }
void stall::stall_width(double w) { stall::width = w; }
void stall::draw()
{
    glBegin(GL_LINES);
    // glLineStipple(1,0x0F0F);//draw the left side of stall
    glVertex2d(anc.getX() * ZOOM, anc.getY() * ZOOM);
    Vec stalllength(0, length);
    Vec b = anc + stalllength;
    glVertex2d(b.getX() * ZOOM, b.getY() * ZOOM);
    glEnd();
    glBegin(GL_LINES);//draw the right side of stall
    Vec stallwidth(width, 0);
    Vec c = anc + stallwidth;
    Vec d = b + stallwidth;
    glVertex2d(c.getX() * ZOOM, c.getY() * ZOOM);
    glVertex2d(d.getX() * ZOOM, d.getY() * ZOOM);
    glEnd();
}
stall::~stall() = default;
Vec stall::getlocate() { return anc + (Vec(width, length) * .5); }
int stall::empty()
{
    return state;
}
pole::pole() = default;
void pole::set(Vec anc, double l, double angle)
{
    pole::Pole_locate = anc;
    pole::pole_length = l;
    pole::angle = angle;
}
void pole::pole_draw()
{
    //set the other side of pole
    Vec temp((-cos((float)angle)) * pole_length, sin((float)angle) * pole_length);
    Vec a = Pole_locate + temp;
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0); // blue
    glVertex2d(Pole_locate.getX() * ZOOM, Pole_locate.getY() * ZOOM);
    glVertex2d(a.getX() * ZOOM, a.getY() * ZOOM);
    glEnd();
}
void pole::getangle()
{
    cout << angle;
}

pole::~pole() = default;
gate::gate() = default;
void gate::gate_(Vec anc, double w, double l)
{
    gate::gate_locate = anc;
    gate::width = w;
    gate::gate_length = l;
}
void gate::gate_draw()
{
    //draw the left side of gate
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2d(gate_locate.getX() * ZOOM, gate_locate.getY() * ZOOM);
    Vec gatelength(0, -gate_length);
    Vec a = gate_locate + gatelength;
    glVertex2d(a.getX() * ZOOM, a.getY() * ZOOM);
    glEnd();
    //draw the right side of gate
    glBegin(GL_LINES);
    Vec gatewidth(-width, 0);
    Vec b = gate_locate + gatewidth;
    Vec c = b + gatelength;
    glColor3f(0.0, 0.0, 0.0);
    glVertex2d(b.getX() * ZOOM, b.getY() * ZOOM);
    glVertex2d(c.getX() * ZOOM, c.getY() * ZOOM);
    glEnd();
}
gate::~gate() = default;
void extrance::set(Vec loc, double gate_wide, double gate_length)
{
    pole a;
    a.pole::set(loc, gate_wide, 0);
    pole1 = a;
    gate b;
    b.gate::gate_(loc, gate_wide, gate_length);
    gate1 = b;
}
void extrance::draw()
{
    gate1.gate_draw();
    pole1.pole_draw();
}
extrance::~extrance() = default;
void Parkinglot::fream()
{
    //draw the whole fream of the parkinglot
    line l1, l2, l3, l4, l5;
    Vec roadwidth_y(0, road_width);
    Vec roadwidth_x(road_width, 0);
    Vec stalllength(0, stall_length);
    Vec stallwidth(stall_width, 0);
    Vec gatewidth(-gate_width, 0);
    Vec goup = roadwidth_y * 2 + stalllength * 2;
    Vec goright1 = stallwidth * stall_num + roadwidth_x;
    Vec gomiddle = goup * (0.5);
    Vec goright2 = stallwidth * stall_num;
    l1.line_(anc + gatewidth, anc + goup + gatewidth);
    l2.line_(anc + gatewidth + goup, anc + goup + goright1);
    l3.line_(anc + goup + goright1, anc + goright1);
    l4.line_(anc + goright1, anc);
    l5.line_(anc + gomiddle, anc + gomiddle + goright2);
}
