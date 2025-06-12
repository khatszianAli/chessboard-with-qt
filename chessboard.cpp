#include <QApplication>
#include "QMainWindow"
#include <QWidget>
#include "QPainter"
#include <QKeyEvent>
#include "QGridLayout"

class ChessBoardWidget: public QWidget {
public:
    static constexpr int TILES = 8;


    explicit ChessBoardWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setMinimumSize(200, 200);
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        setFocusPolicy(Qt::StrongFocus);
    }

protected:
    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        painter.fillRect(rect(), Qt::black);
        int tileSize = qMin(width(), height()) / TILES;
        int boardSize = tileSize * TILES;
        int xOffset = (width() - boardSize) / 2;
        int yOffset = (height() - boardSize) / 2;
        for (int row = 0; row < TILES; row++) {
            for (int col = 0; col < TILES; col++) {
                QColor color = (row + col) % 2 == 0 ? Qt::black : Qt::white;
                painter.fillRect(
                        xOffset + col * tileSize,
                        yOffset + row * tileSize,
                        tileSize, tileSize, color);
            }
        }
    }

};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    auto *window = new QMainWindow;
    window->setWindowTitle("Chessboard");
    window->resize(500, 500);

    auto *chessBoard = new ChessBoardWidget(window);
    window->setCentralWidget(chessBoard);

    window->show();

    return QApplication::exec();
}