public class MergeSort extends Thread {

    public void run() {
        System.out.println("Working");
    }

    public static void merge(PointN[] arr, int l, int m, int r) {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temp arrays
        PointN L[] = new PointN[n1];
        PointN R[] = new PointN[n2];

        // Copy data to temp arrays
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        // Merge the temp arrays
        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarray array
        int k = l;
        while (i < n1 && j < n2) {
            if (L[i].norm() <= R[j].norm()) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy remaining elements of L[] if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy remaining elements of R[] if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Main function that sorts arr[l..r] using
    // merge()
    public static void singleThreadSort(PointN[] pN, int l, int r) {
        if (l < r) {
            // Find the middle point
            int m = (l + r) / 2;

            // singleThreadSort first and second halves
            singleThreadSort(pN, l, m);
            singleThreadSort(pN, m + 1, r);

            // Merge the sorted halves
            merge(pN, l, m, r);
        }
    }

    public static void multiThreadSort(PointN[] pN, int l, int r) {
        if (l < r) {
            // Find the middle point
            int m = (l + r) / 2;

            multiThreadSort(pN, l, m);
            multiThreadSort(pN, m + 1, r);

            // Merge the sorted halves
            merge(pN, l, m, r);
        }
    }

}
