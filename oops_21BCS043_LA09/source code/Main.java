

public class Main{
    public static void main(String[] args){

        // Point p1, p2;
        // p1 = new Point(2 , 3);
        // p2 = new Point(0 , 0);
        // p1.print();
        // System.out.println(p1.distFrom(p2));
        // Point p3;
        // p3 = p1.midPoint(p2);
        // p3.print();


        int size = 10000;

        // Point Cloud
        Point [] pointCloud = new Point [10000];

        for(int i=0; i< size; i++){
            pointCloud[i] = new Point( Math.random()*100, Math.random()*100 );
        }

        double pCentroid_x=0, pCentroid_y=0;
        for(int i=0; i< size; i++){
            pCentroid_x += (pointCloud[i].getX())/size ;
            pCentroid_y += (pointCloud[i].getY())/size ;
        }

        System.out.println( "Point Centroid = " + String.format("%.2f",(pCentroid_x)) + ", " + String.format("%.2f", (pCentroid_y)));

        // Element Cloud
        
        Element [] elementCloud = new Element [10000];
        for(int i=0; i< size; i++){
            elementCloud[i] = new Point( Math.random()*100, Math.random()*100 );
        }

        double eCentroid_x = 0, eCentroid_y=0;
        for(int i=0; i< size; i++){
            eCentroid_x += (((Point)elementCloud[i]).getX())/size ;
            eCentroid_y += (((Point)elementCloud[i]).getY())/size ;
        }

        System.out.println( "Element Centroid = " + String.format("%.2f",(eCentroid_x)) + ", " + String.format("%.2f",(eCentroid_y)) );


        // Problem 3
        Element e;
        Point xp;

        e = new Point(5,6);
        e.print();
        if ( (e instanceof Point) ){
            System.out.println( "Yes, 'e' is a Point type" );
            xp = (Point) e;
            xp.print();
            // xp = (Point) e;
        } else{
            System.out.println( "No, 'e' is not of type Point/" );
        }
    }
}