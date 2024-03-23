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
  while (arr[right] > value) {
    --right;
  }
  int i = 0;
  int g = 1;
  while (i <= right) {
    while (g <= right) {
      if (arr[i] + arr[g] == value) {
        count++;
      }
      g++;
    }
    i++;
    g = i + 1;
  }
  return count;
}

int cbinsearch(int* arr, int left, int right, int value) {
  int middle = left + (right - left) / 2;
  if (right < left) {
    return -42;
  }
  if (arr[middle] == value) {
    return middle;
  }
  if (arr[middle] > value) {
    return cbinsearch(arr, left, middle - 1, value);
  } else {
    return cbinsearch(arr, middle + 1, right, value);
  }
}

int findenteres(int *arr, int len, int value) {
  int index = cbinsearch(arr, 0, len - 1, value);
  if (index == -42) {
    return 0;
  }
  int counter = 1, left = index - 1;
  while (true) {
        if (!(left >= 0 && arr[left] == value)) {
          break;
        }
        left -= 1;
        counter += 1;
  }
  int right = index + 1;
  while (true) {
        if (!(right < 0 && arr[right] == value)) {
          break;
        }
        counter += 1;
        right += 1;
  }
  return counter;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int right = len - 1;
  while (arr[right] > value) {
    --right;
  }
  while (right >= 1) {
    count += findenteres(arr, right - 1, value - arr[right]);
    --right;
  }
  return count;
}
