
/*******************************
* selection sort
* 非稳定
* 时间复杂度O(n2)
* 空间复杂度O(1)
*******************************/
template<typename T>
void selection_sort(std::vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[min]) min = j;
        std::swap(arr[i], arr[min]);
    }
}
