#ifndef GLOBALS_H
#define GLOBALS_H

#include <QtGlobal>
#include <QVector>
#include "point.h"

QT_BEGIN_NAMESPACE
class Qvector<Point> DATA;
QT_END_NAMESPACE

#define MAGIC_NUM 42

extern std::vector<Point> d;

#endif // GLOBALS_H
