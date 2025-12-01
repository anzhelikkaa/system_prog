#include <stdio.h>
#include <dlfcn.h>

int main() {
    void* handle = dlopen("./libmult.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    int (*multiply)(int, int) = dlsym(handle, "multiply");
    if (!multiply) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    printf("Dynamic multiply: %d\n", multiply(3, 7));

    dlclose(handle);
    return 0;
}
