
public class Point implements Element{
    public double _x , _y;

    public Point(){
        // System.out.println("Default Constructor");
    }
    
    public Point(double x, double y){
        // System.out.println("Parameterized Constructor");
        _x = x;
        _y = y;
    }


    public void setCoords(double x, double y){
        _x = x;
        _y = y;
    }

    public void print(){
        System.out.println(_x + " " + _y);
    }

    public double distFrom(Point p){
        double X = (_x - p._x);
        double Y = (_y - p._y);
        double dist = Math.sqrt( X*X + Y*Y );
        return dist;
    }

    public Point midPoint(Point p){
        double X = (_x + p._x)/2;
        double Y = (_y + p._y)/2;
        Point nP;
        nP = new Point(X , Y);
        return nP;
    }

    public double norm(){
        double dist = ((_x*_x) + (_y*_y));
        return dist;
    }

    public double getX(){
        return _x;
    }

    public double getY(){
        return _y;
    }

}