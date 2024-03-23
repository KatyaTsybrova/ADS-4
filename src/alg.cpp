// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int right = len - 1;
  while ( arr[right] > value ) {
    --right;
  }
  int i = 0;
  int g = 1;
  while ( i <= right ) {
    while ( g <= right ) {
      if ( arr[i] + arr[g] == value ) {
        count++;
      }
      g++;
    }
    i++;
    g = i + 1;
  }
  return count;
}

int cbinsearch(int *arr, int size, int value) {
  int count = 0;
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == value) {
        count++;
        int temp = mid - 1;
        while (temp >= 0 && arr[temp] == value) {
            count++;
            temp--;
        }
        temp = mid + 1;
        while (temp < size && arr[temp] == value) {
            count++;
            temp++;
        }
        break;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int right = len - 1;
  while ( arr[right] > value ) {
    --right;
  }
  while ( right >= 1 ) {
    count += cbinsearch(arr, right - 1, value - arr[right]);
    --right;
  }
  return count;
}
