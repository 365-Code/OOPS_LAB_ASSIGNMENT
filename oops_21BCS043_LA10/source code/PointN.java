class PointN implements Element{
    double pointArray[];
    int dimension;
    String name;
    static int counter = 1;

    PointN(){
        dimension = 2;
        pointArray = new double[2];
        name = "Point"+counter;
        counter++;
    }

    PointN(int _dim, double arr[]){
        pointArray = new double[_dim];
        name = "Point"+counter;
        counter++;
        int i = 0;
        for (double d : arr) {
            pointArray[i++] = d;
        }

    }

    PointN(int _dim){
        pointArray = new double[_dim];
        name = "Point"+counter;
        counter++;
        generate_random_points();
    }

    @Override
    public void print(){
        System.out.println("PointN Class with dimensions %.3f" + dimension);
        // System.out.println("Points : ");

        // for (double d : pointArray) {
        //     System.out.println(d+",");
        // }

        System.out.println("\nPoint "+ name + " Norm = "+ norm() + "\n" );

    }

    @Override
    public double norm(){
        double nrm = 0;
        for (double d : pointArray) {
            nrm = d*d;
        }

        return nrm;
    }

    void generate_random_points(){
        for (int i=0; i<pointArray.length; i++) {
            pointArray[i] = Math.round(Math.random() * 100);
        }
    }



}