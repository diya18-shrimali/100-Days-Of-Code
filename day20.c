#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long sum = 0;
    long long count = 0;

    // Using array as hash (assuming sum range manageable)
    // For safety in competitive coding, normally use unordered_map in C++
    long long freq[2 * MAX + 1] = {0};
    int offset = MAX;   // to handle negative sums

    freq[offset] = 1;   // sum = 0 initially

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(freq[sum + offset] > 0)
            count += freq[sum + offset];

        freq[sum + offset]++;
    }

    printf("%lld\n", count);
    return 0;
}