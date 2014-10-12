#include <iostream>

//http://www-numi.fnal.gov/offline_software/srt_public_context/WebDocs/doxygen-howto.html

#ifdef MAC
#include <OpenGL/GL.h>
#include <GLUT/glut.h>
#endif
#ifdef WINDOWS
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#ifdef LINUX
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include "RessourceMgr.h"
#include "DrawableNode.h"
#include "Director.h"
#include "Scene.h"
#include "TextureNode.h"
#include "Clock.h"
#include "Sprite.h"
#include "Animation.h"
#include "Translation.h"
#include "Scale.h"
#include "Rotation.h"
#include "OpacityEffect.h"
#include "Layer.h"
#include "DrawableLine.h"
#include "DrawableRectangle.h"
#include "DrawableCircle.h"
#include "ParticleSequencer.h"
#include "MenuItem.h"

#include <sstream>
#include <float.h>
#include <sys/time.h>

//#include <FTGL/ftgl.h>
//
//#include <FTGL/ftgl.h>


void display();
void reshape(int w, int h);
void init();
void idle();

//FTGLPixmapFont *font;


int main (int argc, char **argv) {

//    std::cout << FLT_MAX << std::endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Texture tests ..");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();

    ke::Director::destroy();
    return 0;
}

void display(){
    ke::Director::getDirector()->drawScene();

    glFlush();
    glutSwapBuffers();
//    glutPostRedisplay();
}

void init(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glEnable(GL_TEXTURE_2D);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA ,GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);

    ke::Director *d = ke::Director::getDirector();
    ke::Scene *s = d->getScene();
    //d->enableCamera(ke::CAM_1);
    //Camera *c = d->getCamera(CAM_1);
    ke::Camera *c = d->getCamera(ke::DEFAULT_CAM);
    ke::Camera *c2 = d->getCamera(ke::CAM_4);

//    c2->setOffset(0,0);
//    c2->setField(320,480);
//    c2->setDimension(320,480);
//    c2->setPosition(0, 0);

    c->setOffset(0,0);
    c->setDimension(640, 480);
    c->setField(640,480);
    c->setPosition(0,0);

    c2->setOffset(0,0);
    c2->setDimension(640, 480);
    c2->setField(640,480);
    c2->setPosition(0,0);

    d->enableCamera(ke::CAM_4);
    d->disableCamera(ke::DEFAULT_CAM);

    ke::Layer *l = new ke::Layer();
    l->setZIndex(0);

//    for(int i = 0; i<2000; i+=30){
//        ke::DrawableLine *col = new ke::DrawableLine(i,0,i,5000);
//        col->setOpacity(1);
//        col->setColor(1,0,0);
//        col->setZIndex(3);
//        std::ostringstream oss;
//        oss << i;
//
//        //l->add(col);
//    }
//
//    for(int j = 0; j<2000; j+=30){
//        ke::DrawableLine *row = new ke::DrawableLine(0,j,5000,j);
//        row->setOpacity(1);
//        row->setColor(1,0,0);
//        row->setZIndex(3);
//        std::ostringstream oss;
//        oss << j;
//        //l->add(row);
//    }

    ke::Menu *m = new ke::Menu();
    ke::MenuItem *mi = new ke::MenuItem();
    mi->setTexture(new ke::Texture2D("ressources/arbre_1.png"));
    m->add(mi);
    mi->setScale(0.02, 0.02);

    d->addMenu(m);

    ke::Sprite *a2 = new ke::Sprite("ressources/herbe.png");
    a2->setPosition(-320,-240);
    a2->setOpacity(1);
    a2->setAnchor(0,0);
    a2->setScale(1,1);
    a2->setZIndex(0);
    l->add(a2);

    ke::DrawableLine *row = new ke::DrawableLine(0,0,500,500);
    row->setOpacity(1);
    row->setColor(0,1,1);
    row->setZIndex(13);
    l->add(row);

    ke::DrawableCircle *cer = new ke::DrawableCircle(50, 50, 30);
    cer->setOpacity(1);
    cer->setColor(1,0,1);
    cer->setZIndex(12);
    l->add(cer);

    ke::Layer *l2 = new ke::Layer();
    l2->setZIndex(20);

    ke::Image *img = new ke::Image("ressources/arbre_1.png");

    ke::Sprite *a1 = new ke::Sprite(new ke::Texture2D(img));

    a1->setPosition(40,50);
    a1->setOpacity(1);
    a1->setAnchor(0,0);
    a1->setScale(0.07,0.07);
    a1->setZIndex(1);
    l2->add(a1);

    ke::Sprite *a11 = new ke::Sprite("ressources/arbre_1.png");
    a11->setPosition(290,10);
    a11->setOpacity(1);
    a11->setAnchor(0,0);
    a11->setScale(0.07,0.07);
    a11->setZIndex(10);
    l2->add(a11);

    ke::Sprite *a121 = new ke::Sprite("ressources/arbre_1.png");
    a121->setPosition(440,70);
    a121->setOpacity(1);
    a121->setAnchor(0,0);
    a121->setScale(0.07,0.07);
    a121->setZIndex(1);
    l2->add(a121);

//    ke::Sprite *a21 = new ke::Sprite("/Users/arnaudboeglin/Desktop/DSCN6200.jpg");
//    a21->setPosition(120,70);
//    a21->setOpacity(1);
//    a21->setAnchor(0,0);
//    a21->setScale(0.1,0.1);
//    a21->setZIndex(0.5);
//    l2->add(a21);

    ke::Sprite *a12 = new ke::Sprite("ressources/fleurs_violette.png");
    a12->setPosition(150,70);
    a12->setOpacity(1);
    a12->setAnchor(0,0);
    a12->setScale(0.1,0.1);
    a12->setZIndex(1.5);
    l2->add(a12);

    ke::Sprite *pc = new ke::Sprite("ressources/petits_cailloux.png");
    pc->setPosition(120,10);
    pc->setOpacity(1);
    pc->setAnchor(0,0);
    pc->setScale(0.1,0.1);
    pc->setZIndex(1.7);
    l2->add(pc);

    ke::Sprite *pcv = new ke::Sprite("ressources/herbe_longue.png");
    pcv->setPosition(180,10);
    pcv->setOpacity(1);
    pcv->setAnchor(0,0);
    pcv->setScale(0.1,0.1);
    pcv->setZIndex(1.8);
    l2->add(pcv);


    ke::Sprite *ca = new ke::Sprite("ressources/caillou.png");
    ca->setPosition(150,160);
    ca->setOpacity(1);
    ca->setAnchor(0,0);
    ca->setScale(0.4,0.4);
    ca->setZIndex(1.1);
    l2->add(ca);

    ke::Sprite *sp = new ke::Sprite("ressources/mouv_1.png");
//    ke::Sprite *sp2 = new ke::Sprite("/Users/arnaudboeglin/tmp/imgs/mouv_1.png");
    sp->setZIndex(5);
    sp->move(50,50);
//    sp->setRotation(90);
//    sp->setAnchor(30, -50);
//    sp2->move(150,150);
//    sp->add(sp2);
//    sp2->setZIndex(10);
//    sp2->setRotation(-30);
//    sp->attachCamera(c);
//    sp2->attachCamera(c);
//
//    ke::Sprite *sp = new ke::Sprite("/Users/arnaudboeglin/tmp/imgs/mouv_1.png");

    ke::DrawableRectangle *rect = new ke::DrawableRectangle(61,61,28,28);
    rect->setOpacity(1);
    rect->setColor(0,1,0);
    rect->setFill(true);
    rect->setZIndex(4);
    rect->setRotation(45);
    l->add(rect);

    l2->add(sp);

    s->add(l2);
    s->add(l);

    ke::Animation *sa = new ke::Animation("mouvement");
//
    for(int i=0; i<1; i++){
        sa->addTexture(new ke::Texture2D("ressources/mouv_1.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_2.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_3.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_4.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_5.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_6.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_7.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_8.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_9.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_10.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_11.png"));
        sa->addTexture(new ke::Texture2D("ressources/mouv_1.png"));
//        sa->addTexture(new ke::Texture2D("/Users/arnaudboeglin/tmp/imgs/imgs/mouv_7.png"));
//        sa->addTexture(new ke::Texture2D("/home/jonas/Bureau/img/mouv_8.png"));
//        sa->addTexture(new ke::Texture2D("/home/jonas/Bureau/img/mouv_9.png"));
//        sa->addTexture(new ke::Texture2D("/home/jonas/Bureau/img/mouv_10.png"));
//        sa->addTexture(new ke::Texture2D("/home/jonas/Bureau/img/mouv_11.png"));
//
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_1.png"));
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_2.png"));
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_3.png"));
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_4.png"));
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_5.png"));
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_6.png"));
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_7.png"));
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_8.png"));
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_9.png"));
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_10.png"));
//        //    sa->addTexture(new Texture2D("/home/jonas/Bureau/img/mouv_11.png"));
    }
    sa->setDuration(1);

    ke::Translation *st = new ke::Translation("move", 1, 50, 0);
    ke::Rotation *ra = new ke::Rotation("rotation", 2, 180);
    ke::Scale *sc = new ke::Scale("scale", 1, 10, 10);
    ke::OpacityEffect *oa = new ke::OpacityEffect("appears", 1);
    oa->setFinalOpacity(1.F);
    oa->setAutoRepeat(true);
    ra->setAutoRepeat(true);
    st->setAutoRepeat(true);
    sc->setAutoRepeat(true);
    sa->setAutoRepeat(true);

    ke::FireSequencer *fs = new ke::FireSequencer();
    fs->setZIndex(300);
    s->add(fs);
    
//    std::cout << "constructed" << std::endl;

//    sp->setOpacity(0.5f);
    sp->move(200,0);
//    sp->add
    sp->addAnimation(sa);
    sp->addAnimation(st);
//    sp->addAnimation(ra);
//    sp->addAnimation(sc);
//    sp->addAnimation(oa);
    sp->setOpacity(1.f);

//    a1->attachCamera(c);

//    sp->hide();

//    sp->playAnimation("appears");
//    sp->playAnimation("scale");

    sp->playAnimation("mouvement");
    sp->playAnimation("move");

//    sp->stopAnimation("move");
//    sp->stopAnimation("mouvement");

//        sp->playAnimation("rotation");

    c2->setNodeToFollow(sp);

    std::cout << sp->getAbsoluteX() << std::endl;
    std::cout << sp->getWidth() << std::endl;

//    ke::Sprite *s5 = new ke::Sprite("ressources/ok2.bmp");
//    ke::Sprite *s5 = new ke::Sprite("/Users/arnaudboeglin/Desktop/ok.bmp");
//    s5->setRotation(180);
//    s5->hide();
//    s5->setZIndex(100);
//    s5->attachCamera(c);
//    s->add(s5);

}

void reshape(int w, int h){
//    Camera *c = Director::getDirector()->getCamera(DEFAULT_CAM);
//    c->setDimension(w, h);
//    c->setField(w, h);
}

void idle(){
    static int w = glutGet(GLUT_ELAPSED_TIME);

    int t = glutGet(GLUT_ELAPSED_TIME);

    if( t > w ){
        glutPostRedisplay();
        w = t + 1000/30;
    }
}
