import java.time.Duration;
import java.time.Instant;

public class OOPs {

    public static void main(String args[]) {

        int[] SIZE = { 10, 100, 1000, 10000, 100000 };
        // int[] SIZE = {100};

        // int SZE = SIZE[3];
        // PointN[] pArr = new PointN[SZE];

        System.out.println("Single Thread Sorting");

        for (int S : SIZE) {
            PointN[] pArr = new PointN[S];
            for (int i = 0; i < S; i++) {
                pArr[i] = new PointN((int) Math.round((Math.random() * 10) + 2));
            }

            Instant start = Instant.now();
            MergeSort.singleThreadSort(pArr, 0, S - 1);
            Instant end = Instant.now();
            Duration timeElapsed = Duration.between(start, end);
            System.out.println("Size: " + S + ",Time taken: " + timeElapsed.toMillis() + " milliseconds");
            for(int i=0; i<S; i++){
                System.out.println("Point"+pArr[i].name+" Norm ="+pArr[i].norm());
            }
        }

        // System.out.println("Multi Thread Sorting");
        // for (int S : SIZE) {
        // PointN[] pArr = new PointN[S];
        // for (int i=0; i<S; i++) {
        // pArr[i] = new PointN( (int)Math.round((Math.random()+0.2)*10) );
        // }

        // Instant start = Instant.now();
        // MergeSort.multiThreadSort(pArr, 0, S-1);
        // Instant end = Instant.now();
        // Duration timeElapsed = Duration.between(start, end);
        // System.out.println("Size: "+ S +",Time taken: "+ timeElapsed.toMillis() +"
        // milliseconds");

        // }

        System.out.println("Multithreading");
        for (int S : SIZE) {

            PointN[] pN = new PointN[S];
            for (int i = 0; i < S; i++) {
                pN[i] = new PointN((int) Math.round((Math.random() * 10) + 2));
            }

            Instant start = Instant.now();
            // MergeSort.multiThreadSort(pN, 0, SIZE[0]);
            // int mid2 = (mid1+0)/2;

            Thread t1 = new Thread(() -> MergeSort.multiThreadSort(pN, 0, S / 2 - 1));
            Thread t2 = new Thread(() -> MergeSort.multiThreadSort(pN, S / 2, S - 1));

            t1.start();
            t2.start();

            try {
                t1.join();
                t2.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            MergeSort.merge(pN, 0, S / 2 - 1, S - 1);

            Instant end = Instant.now();
            Duration timeElapsed = Duration.between(start, end);
            System.out.println("Size: " + S + ",Time taken: " + timeElapsed.toMillis() + " milliseconds");
        }

        // System.out.println("\nBefore Sorting");
        // for (int i=0; i<SZE; i++) {
        // System.out.println( pArr[i].name+ " " + pArr[i].norm());
        // }

        // Instant start = Instant.now();
        // MergeSort.singleThreadSort(pArr, 0, SZE-1);
        // Instant end = Instant.now();
        // Duration timeElapsed = Duration.between(start, end);
        // System.out.println("Time taken: "+ timeElapsed.toMillis() +" milliseconds");

        System.exit(0);

    }
}
