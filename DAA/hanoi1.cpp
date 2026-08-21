#include <iostream>
#include <stack>

struct HanoiState {
    int n;
    char src;
    char aux;
    char dest;
    int step;
};

void towersOfHanoiIterative(int n, char source, char auxiliary, char destination) {
    std::stack<HanoiState> stack;
    stack.push({n, source, auxiliary, destination, 1});
    
    while (!stack.empty()) {
        HanoiState curr = stack.top();
        stack.pop();
        
        if (curr.n == 0) continue;
        
        if (curr.step == 1) {
            stack.push({curr.n, curr.src, curr.aux, curr.dest, 2});
            stack.push({curr.n - 1, curr.src, curr.dest, curr.aux, 1});
        } 
        else if (curr.step == 2) {
            std::cout << "Move disk " << curr.n << " from " << curr.src << " to " << curr.dest << "\n";
            stack.push({curr.n, curr.src, curr.aux, curr.dest, 3});
            stack.push({curr.n - 1, curr.aux, curr.src, curr.dest, 1});
        }
        else if (curr.step == 3) {
            continue;
        }
    }
}

int main() {
    std::cout << "=== 1b. Towers of Hanoi (Iterative/Non-Recursive, 3 disks) ===\n";
    towersOfHanoiIterative(3, 'A', 'B', 'C');
    return 0;
}
