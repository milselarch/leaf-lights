void sort(float a[], int size) {
    for (int i=0; i<(size-1); i++) {
        for (int o = 0; o < (size-(i+1)); o++) {
            if (a[o] > a[o+1]) {
                float t = a[o];
                a[o] = a[o+1];
                a[o+1] = t;
            }
        }
    }
}

