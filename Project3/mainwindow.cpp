#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBrush>
#include <QMediaPlayer>

extern QMediaPlayer* birdPlayer;

using namespace std;

extern QMediaPlayer* birdPlayer;
extern QMediaPlayer* woodPlayer;
extern QMediaPlayer* pigPlayer;
extern Score* score;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    x(0),
    y(0),
    index(0),
    press(false),
    super(false),
    started(false)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/bg.png")));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    world = new b2World(b2Vec2(0.0f, -9.8f));

    score = new Score();
    birdPlayer = new QMediaPlayer();
    woodPlayer = new QMediaPlayer();
    pigPlayer = new QMediaPlayer();

    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 250;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

void MainWindow::start()
{/*
    scene->clear();
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/bg.png")));
*/
    delete playButton;
    started = true;
    scene->addItem(score);

    itemList.push_back(new Land(16,1.5,32,3,QPixmap(":/NOTHING.png").scaled(width(),height()/6.0),world,scene));

    float woodSize = 0.525;
    float scalar = 16;
    itemList.push_back(new Wood(24.0f,5.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(24.0f,4.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(24.0f,3.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(25.1f,4.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(22.9f,4.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Pig(25.1f,3.6f,woodSize,woodSize,&timer,QPixmap(":/pig.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Pig(22.9f,3.6f,woodSize,woodSize,&timer,QPixmap(":/pig.png").scaled(height()/scalar,height()/scalar),world,scene));

    itemList.push_back(new Wood(19.0f,5.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(19.0f,4.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(19.0f,3.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(20.1f,4.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(17.9f,4.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Pig(20.1f,3.6f,woodSize,woodSize,&timer,QPixmap(":/pig.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Pig(17.9f,3.6f,woodSize,woodSize,&timer,QPixmap(":/pig.png").scaled(height()/scalar,height()/scalar),world,scene));

    itemList.push_back(new Wood(12.9f,5.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(12.9f,4.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(12.9f,3.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(14.0f,5.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(14.0f,3.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(15.1f,5.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Wood(15.1f,3.6f,woodSize,woodSize,&timer,QPixmap(":/wood1.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Pig(14.0f,4.6f,woodSize,woodSize,&timer,QPixmap(":/pig.png").scaled(height()/scalar,height()/scalar),world,scene));
    itemList.push_back(new Pig(15.1f,4.6f,woodSize,woodSize,&timer,QPixmap(":/pig.png").scaled(height()/scalar,height()/scalar),world,scene));

    // Create bird (You can edit here)
    bird[0] = new Bird(3.2f,7.5f,0.3f,&timer,QPixmap(":/bird.png").scaled(height()/16.0,height()/16.0),world,scene);
    bird[1] = new YellowBird(0,8.5,0.3f,&timer,QPixmap(":/yellow.png").scaled(height()/16.0,height()/16.0),world,scene);
    bird[2] = new BlueBird(0,10,0.25f,&timer,QPixmap(":/blue.png").scaled(height()/20.0,height()/20.0),world,scene);
    bird[3] = new WhiteBird(0,11.5,0.35f,&timer,QPixmap(":/white.png").scaled(height()/14.0,height()/12.0),world,scene);
    bird[4] = new YellowBird2(0,13,0.3f,&timer,QPixmap(":/yellow2.png").scaled(height()/16.0,height()/16.0),world,scene);
    bird[5] = new BlueBird2(0,14.5,0.25f,&timer,QPixmap(":/blue2.png").scaled(height()/20.0,height()/20.0),world,scene);
    bird[6] = new WhiteBird2(0,16,0.35f,&timer,QPixmap(":/white2.png").scaled(height()/14.0,height()/12.0),world,scene);
    birdie = bird[0];
    cout << "restart yeah" << endl;

}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    if(!started)
        return false;
    if(index > NUM_OF_BIRD + 1)
        return false;
    if(score->getScore() == 30000){
        cout << "\nwin index = " << index << endl;
        gameOver(true);
        index = NUM_OF_BIRD + 2;
    }else if(index == NUM_OF_BIRD + 1){
        index++;
        cout << "\nlose index = " << index << endl;
        gameOver(false);
        return false;
    }
    if(event->type() == QEvent::MouseButtonPress)
    {
        if(index == NUM_OF_BIRD)
            index++;

        if(press || index > NUM_OF_BIRD)
            return false;
        else
            press = true;

        initialX = QCursor::pos().x();
        initialY = QCursor::pos().y();
        if(super){
            birdie->superPower(&timer, height(),world, scene);
            super = false;
        }
    }
    if(event->type() == QEvent::MouseMove)
    {   
        if(index >= NUM_OF_BIRD)
            return false;

        if(x != 0 && birdie->g_body == NULL && press){
            if(pow(QCursor::pos().x() - initialX,2) + pow(QCursor::pos().y() - initialY,2)> 10000)
                return false;
            x = QCursor::pos().x() - x;
            y = QCursor::pos().y() - y;
            birdie->mappedPoint.setX(birdie->mappedPoint.x() + x);
            birdie->mappedPoint.setY(birdie->mappedPoint.y() + y);
        }
        x = QCursor::pos().x();
        y = QCursor::pos().y();
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        if(!press)
            return false;
        else
            press = false;

        if(birdie->g_body == NULL){
            birdie->createBody();
            birdie->setLinearVelocity(b2Vec2((initialX - QCursor::pos().x())/5, (QCursor::pos().y() - initialY)/5));

            if(index >= 1)
                delete bird[index-1];

            if(index == 0){
                birdie = bird[++index];
                birdie->mappedPoint.setX(110);
                birdie->mappedPoint.setY(320);
                return false;
            }
            super = true;

        }else if(!super){
            birdie = bird[++index];
            if(index >= NUM_OF_BIRD)
                return false;
            birdie->mappedPoint.setX(110);
            birdie->mappedPoint.setY(320);
        }
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::restart()
{
    //////////////////
    //don't know how to delete all object before restart!
    //////////////////
    delete bird[6];
    /*
    if(index == 9)
        delete bird[NUM_OF_BIRD - 1];
    else if(index < NUM_OF_BIRD)
        for(; index < NUM_OF_BIRD; ++index)
            delete bird[index];
*/
    //finish = true;
    x = 0;
    y = 0;
    index = 0;
    press = false;
    super = false;
    delete quitButton;
    delete text;
    score->resetScore();
//    for(int i = 0; i < 23 ; ++i){
  //      if(!itemList[i]->isEnabled())
    //        cout << "i = " << i << " enabled" << endl;
    //}

//    for(int i = 0; i < itemList.count()-1; ++i)
//        itemList[i+1]->deleteLater();

   //while(!itemList.isEmpty())
     //  itemList.takeFirst();

    start();
}


void MainWindow::gameOver(bool win)
{
    started = false;

    if(win){
        text = new QGraphicsTextItem(QString("LEVEL CLEARED!"));
        birdPlayer->setMedia(QUrl("qrc:win.mp3"));
        birdPlayer->play();
    }
    else{
        text = new QGraphicsTextItem(QString("LEVEL FAILED!"));
        birdPlayer->setMedia(QUrl("qrc:lose.mp3"));
        birdPlayer->play();
    }

    QFont titleFont("comic sans",80);
    text->setFont(titleFont);
    text->setDefaultTextColor(Qt::white);
    int txPos = this->width()/2 - text->boundingRect().width()/2;
    int tyPos = 100;
    text->setPos(txPos,tyPos);
    scene->addItem(text);

    playButton = new Button(QString("Play Again"));
    playButton->setPos(this->width()/2 - playButton->boundingRect().width()/2, 250);
    connect(playButton,SIGNAL(clicked()),this,SLOT(restart()));
    scene->addItem(playButton);

    quitButton = new Button(QString("Quit"));
    quitButton->setPos(this->width()/2 - quitButton->boundingRect().width()/2,350);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quit()));
    scene->addItem(quitButton);
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::quit()
{
    close();
}
