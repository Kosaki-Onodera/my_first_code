#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define WIDTH 80      
#define HEIGHT 21     // 控制台高度（奇数以便有中间行）

typedef struct Canvas
{
    char canvas[WIDTH][HEIGHT];
    int height;
    int width;
}Canvas;

int main() {
    Canvas canvas = { 0 };
    canvas.width = WIDTH;
    canvas.height = HEIGHT;

    printf("\n正弦函数 y = sin(x) (0到2π)\n");
    printf("==============================\n\n");

    initCanvas(&canvas);
    drawSinWave(&canvas);
    printCanvas(&canvas);

    // 添加x轴标签
    printf("\n");
    addAxisLabels(&canvas);

    printf("\n振幅: 1.0 | 周期: 2π ≈ 6.283\n");
    printf("'*' 表示sin(x)的值\n");

    return 0;
}

void initCanvas(Canvas* c) {
    for (int y = 0; y < c->height; y++) {
        for (int x = 0; x < c->width; x++) {
            if (y == c->height / 2) {
                c->canvas[y][x] = '-';  // x轴
            }
            else if (x == 0 || x == c->width - 1) {
                c->canvas[y][x] = '|';  // 左右边框
            }
            else {
                c->canvas[y][x] = ' ';
            }
        }
    }
}
void drawPoint(Canvas* c, int x, int y) {
    if (x >= 0 && x < c->width && y >= 0 && y < c->height) {
        c->canvas[y][x] = '*';
    }
}
void drawSinWave(Canvas* c) {
    double amplitude = (c->height - 1) / 2.0 * 0.8;
    int centerY = c->height / 2;
    // 0到2π映射到整个画布宽度
    for (int plotX = 1; plotX < c->width - 1; plotX++) {
        // 将plotX映射到0到2π
        double x = 2 * PI * (plotX - 1.0) / (c->width - 3.0);
        double y = sin(x);
        int plotY = (int)(centerY - y * amplitude);
        drawPoint(c, plotX, plotY);
    }
}

void addAxisLabels(Canvas* c) {
    int centerY = c->height / 2;

    // 标记0, π/2, π, 3π/2, 2π
    char* labels[] = { "0", "π/2", "π", "3π/2", "2π" };
    int positions[] = { 1, (c->width - 3) / 4, (c->width - 3) / 2, 3 * (c->width - 3) / 4, c->width - 2 };

    for (int i = 0; i < 5; i++) {
        // 在x轴上标记
        c->canvas[centerY][positions[i]] = '+';

        // 在下方添加标签（简单实现）
        printf("    ");  // 对齐颗粒度
        printf("请输入一个标签：例如ABCD，方便后续操作");
        for (int j = 0; j < positions[i]; j++) {
            if (j == positions[i] - 1) {
                printf("%s", labels[i]);
                break;
            }
            else {
                printf(" ");
            }
        }
    }
    printf("\n");
}

void printCanvas(Canvas* c) {
    for (int y = 0; y < c->height; y++) {
        for (int x = 0; x < c->width; x++) {
            putchar(c->canvas[y][x]);
        }
        putchar('\n');
    }
}

int main() {
    Canvas canvas = { 0 };
    canvas.width = WIDTH;
    canvas.height = HEIGHT;

    printf("\n正弦函数 y = sin(x) (0到2π)\n");
    printf("==============================\n\n");

    initCanvas(&canvas);
    drawSinWave(&canvas);
    printCanvas(&canvas);

    // 添加x轴标签
    printf("\n");
    addAxisLabels(&canvas);

    printf("\n振幅: 1.0 | 周期: 2π ≈ 6.283\n");
    printf("'*' 表示sin(x)的值\n");

    return 0;
}