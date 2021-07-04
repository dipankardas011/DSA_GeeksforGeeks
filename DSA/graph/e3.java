package graph;

class e3 {

    public int min_diff;

    void TugOfWar(int arr[], int n, boolean curr_element[], int no_of_selected_elements, 
            boolean soln[], int sum,
            int curr_sum, int curr_position) {
        // if outof bound
        if (curr_position == n)
            return;
        // check that the number of elements left
        // are not less than the number of elements
        // required to form the solution
        if ((n / 2 - no_of_selected_elements) > (n - curr_position))
            return;

        TugOfWar(arr, n, curr_element, no_of_selected_elements, soln, sum, curr_sum, curr_position + 1);
        no_of_selected_elements++;
        curr_sum = curr_sum + arr[curr_position];
        curr_element[curr_position] = true;

        if (no_of_selected_elements == n / 2) {
            if (Math.abs(sum / 2 - curr_sum) < min_diff) {
                min_diff = Math.abs(sum / 2 - curr_sum);
                for (int i = 0; i < n; i++)
                    soln[i] = curr_element[i];
            }
        } else {
            TugOfWar(arr, n, curr_element, no_of_selected_elements, soln, sum, curr_sum, curr_position + 1);
        }
        curr_element[curr_position] = false;
    }

    void exec(int arr[]) {
        int n = arr.length;
        boolean curr_element[] = new boolean[n];
        boolean soln[] = new boolean[n];
        min_diff = Integer.MAX_VALUE;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            curr_element[i] = soln[i] = false;
        }
        // Find the solution using recursive
        // function TOWUtil()
        TugOfWar(arr, n, curr_element, 0, soln, sum, 0, 0);

        // Print the solution
        System.out.print("The first subset is: ");
        for (int i = 0; i < n; i++) {
            if (soln[i] == true)
                System.out.print(arr[i] + " ");
        }
        System.out.print("\nThe second subset is: ");
        for (int i = 0; i < n; i++) {
            if (soln[i] == false)
                System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        int arr[] = { 23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4 };
        e3 a = new e3();
        a.exec(arr);
    }
}