//
// Created by Mohammad  Boustta on 6/2/21.
//
#include "philosophers.h"


static void greeting(size_t& i) {
cout << oslock << "Hello, world! I am thread " << i << endl << osunlock;
}

static const size_t kNumFriends = 6;
int main(int argc, char *argv[]) {
    cout << "Let's hear from " << kNumFriends << " threads." << endl;
    thread friends[kNumFriends]; // declare array of empty thread handles
    // Spawn threads
    for (size_t i = 0; i < kNumFriends; i++) {
        friends[i] = thread(greeting, ref(i));
    }
    // Wait for threads
    for (size_t i = 0; i < kNumFriends; i++) {
        friends[i].join();
    }
    cout << "Everyone's said hello!" << endl;
    return 0;
}