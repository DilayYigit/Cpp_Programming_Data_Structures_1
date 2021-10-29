/*
 * @author: Dilay Yigit
 * @date: 05.07.2021
 */

#include <chrono>
#include <iostream>
using namespace std;

/* Algorithm 1
 * @return the maximum sum of the subsequence
*/
int maxSubSum1(int arr[], int n) {
    int maxSum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            int thisSum = 0;

            for (int k = i; k <= j; k++) {
                thisSum += arr[k];
            }

            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

/* Algorithm 2
 * @return the maximum sum of the subsequence
*/
int maxSubSum2 (int arr[], int n) {
    int maxSum = 0;

    for (int i = 0; i < n; i++) {
        int thisSum = 0;

        for (int j = i; j < n; j++) {

            thisSum += arr[j];

            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

/* Helper function for Algorithm 3
 * @return the maximum integer from 3 integer input
*/
int max3 (int a, int b, int c) {
    if (a > b) {
        if (a > c)
            return a;
    }
    else if (b > a) {
        if (b > c)
            return b;
    }
    else if (c > b) {
        if (c > a)
            return c;
    }
}

/* Recursive function for Algorithm 3
 * @return the maximum sum of the subsequence
*/
int maxSumRecursive (int arr[], int left, int right) {
    if (left == right) { //Base case
        if (arr[left] > 0) {
            return arr[left];
        }
        else
            return 0;
    }

    int center = (left + right) / 2;
    int maxLeftSum = maxSumRecursive(arr, left, center);
    int maxRightSum = maxSumRecursive(arr, center + 1, right);

    int maxLeftBorderSum = 0;
    int leftBorderSum = 0;

    for (int i = center; i >= left; i--) {
        leftBorderSum += arr[i];

        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0;
    int rightBorderSum = 0;

    for (int j = center + 1; j <= right; j++) {
        rightBorderSum += arr[j];

        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3 (maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);

}

/* Algorithm 3
 * @return the output of 'maxSumRecursive' function
*/
int maxSubSum3 (int arr[], int n) {
    return maxSumRecursive(arr, 0, n - 1);
}

/* Algorithm 4
 * @return the maximum sum of the subsequence
*/
int maxSubSum4 (int arr[], int n) {
    int maxSum = 0;
    int thisSum = 0;

    for (int j = 0; j < n; j++) {
        thisSum += arr[j];

        if (thisSum > maxSum) {
            maxSum = thisSum;
        }
        else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}

/* Helper function to test the program
 * @param arr[] - integer array as input
 * @param n - size of the array
 * @param algorithmNo - specific number for each algorithm
 * This method prints the execution time.
*/
void test (int *arr, int n, int algorithmNo) {
    chrono::time_point< chrono::system_clock > startTime;
    chrono::duration< double, milli > elapsedTime;

    startTime = chrono::system_clock::now();

    if (algorithmNo == 1) {
        maxSubSum1(arr, n);
    }
    else if (algorithmNo == 2) {
        maxSubSum2(arr, n);
    }
    else if (algorithmNo == 3) {
        maxSubSum3(arr, n);
    }
    else if (algorithmNo == 4) {
        maxSubSum4(arr, n);
    }

    elapsedTime = chrono::system_clock::now() - startTime;
    cout << "-------------------------------------------------" << endl;
    cout << "Algorithm " << algorithmNo << " for size " << n << "." << endl;
    cout << "Execution took " << elapsedTime.count() << " miliseconds. " << endl;
}

int main() {

    // here, we use for loop to create different size of arrays,
    // and assign random values between -50 to +50 to the array.
    // I did not use all i values from here to create my table.

    for (int i = 50; i <= 1000000; i*=2) {
        int arr[i];
        for (int j = 0; j < i; j++) {
            arr[j] = rand() % 101 + (-50);
        }
        test(arr, i, 4);
        test(arr, i, 3);
        if (i >= 409600)
            // Because execution took very long time, I skip.
            continue;
        test(arr, i, 2);
        if (i >= 6400)
            // Because execution took very long time, I skip.
            continue;
        test(arr, i, 1);
    }


    // here, I test specific array sizes that I want to use in my table.
    int size = 1000000;
    int arr1[size];
    for (int i = 0; i < size; i++) {
        arr1[i] = rand() % 101 + (-50);
    }
    test(arr1, size, 2);
    test(arr1, size, 1);


    size = 10;
    int arr2[size];
    for (int i = 0; i < size; i++) {
        arr2[i] = rand() % 101 + (-50);
    }
    test(arr2, size, 4);
    test(arr2, size, 3);
    test(arr2, size, 2);
    test(arr2, size, 1);


    return 0;
}





















