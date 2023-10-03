#include <stdio.h>



struct ITEM {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};

void maxHeapify(struct ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        struct ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(struct ITEM arr[], int n) {
	int i;
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapSort(struct ITEM arr[], int n) {
    buildMaxHeap(arr, n);
    int i;

    for (i = n - 1; i > 0; i--) {
        struct ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
    }
}

double fractionalKnapsack(struct ITEM arr[], int n, double capacity) {
    heapSort(arr, n);

    double total_profit = 0;
    double current_weight = 0;
    int i;
    for ( i = 0; i < n; i++) {
        if (current_weight + arr[i].item_weight <= capacity) {
            current_weight += arr[i].item_weight;
            total_profit += arr[i].item_profit;
        } else {
            double remaining_capacity = capacity - current_weight;
            total_profit += arr[i].profit_weight_ratio * remaining_capacity;
            break;
        }
    }

    return total_profit;
}

int main() {
    int n=100;
    int i;
    struct ITEM items[n];
    for ( i = 0; i < n; i++) {
        
        items[i].item_id = i + 1;
        items[i].item_profit=(rand() % (95 - 35+ 1)) + 35;
        items[i].item_weight=(rand() % (75 - 25+ 1)) + 25;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    double capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%lf", &capacity);

    double max_profit = fractionalKnapsack(items, n, capacity);

    printf("Maximum profit: %.2lf\n", max_profit);

    return 0;
}