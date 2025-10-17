#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// 使用 long long 以防止計算過程中發生溢位
using ll = long long;

// 計算序列的 hash 值
ll calculate_hash(const std::vector<int>& seq, ll X, ll Y) {
    ll V = 0;
    for (int val : seq) {
        V = (V * X + val) % Y;
    }
    return V;
}

// 基數排序函數
// arr: 待排序的向量
// n: 向量的大小
// max_val: 向量中的最大值，用來決定排序的輪數
void radix_sort(std::vector<int>& arr, int n, int max_val) {
    // 選擇 2^8 = 256 作為基數。
    // 這意味著我們一次處理 8 個位元 (bits)。
    // 提取位數的操作可以用高效的位元運算完成。
    const int BITS_PER_PASS = 6;
    const int BASE = 1 << BITS_PER_PASS; // 1 << 8 = 256
    const int MASK = BASE - 1;           // 255 (二進位為 0b11111111)

    // 建立一個輔助陣列，用於暫存每一輪排序的結果
    std::vector<int> buffer(n);
    // 計數陣列，大小為 BASE
    std::vector<int> count(BASE);

    int shift = 0;
    // 進行排序，直到處理完所有位元
    // 只要 max_val 右移 shift 位後還不為 0，表示還有更高的位元需要排序
    while ((max_val >> shift) > 0) {
        // --- 使用計數排序對當前位數進行排序 ---

        // 1. 計數 (Counting)
        // 將計數陣列歸零
        std::fill(count.begin(), count.end(), 0);
        // 統計當前位數 (由 shift 和 MASK 決定) 的每個值出現的次數
        for (int i = 0; i < n; ++i) {
            int digit = (arr[i] >> shift) & MASK;
            count[digit]++;
        }

        // 2. 計算前綴和 (Prefix Sum)
        // count[i] 將儲存 <= i 的元素個數
        for (int i = 1; i < BASE; ++i) {
            count[i] += count[i - 1];
        }

        // 3. 放置 (Placing)
        // 從後往前遍歷原陣列，以保證排序的穩定性
        for (int i = n - 1; i >= 0; --i) {
            int digit = (arr[i] >> shift) & MASK;
            // count[digit] - 1 是當前元素排序後的位置
            buffer[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // 4. 複製 (Copying)
        // 將排好序的 buffer 複製回 arr，準備下一輪排序
        arr = buffer;

        // 處理下 8 個位元
        shift += BITS_PER_PASS;
    }
}

void solve() {
    ll n, a, b, c, x, y;
    std::cin >> n >> a >> b >> c >> x >> y;

    std::vector<int> S(n);
    S[0] = a;
    int max_val = a;
    for (int i = 1; i < n; ++i) {
        // 注意這裡 S[i-1] 需要是 long long 以免乘法溢位
        S[i] = (static_cast<ll>(S[i - 1]) * b + a) % c;
        if (S[i] > max_val) {
            max_val = S[i];
        }
    }

    // 對生成的序列 S 進行基數排序
    radix_sort(S, n, max_val);

    // 計算排序後序列的 hash 值並輸出
    std::cout << calculate_hash(S, x, y) << "\n";
}

int main() {
    // 高速 I/O 設定
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int TC;
    std::cin >> TC;
    while (TC--) {
        solve();
    }

    return 0;
}