#include "TweenPropType.h"
#include "TweenValue.h"
#include "GObject.h"
#include "GProgressBar.h"

NS_FGUI_BEGIN
USING_NS_CC;

void TweenPropTypeUtils::setProps(GObject * target, TweenPropType propType, const TweenValue & value)
{
    GObject* g = dynamic_cast<GObject*>(target);
    if (g == nullptr)
        return;

    switch (propType)
    {
    case TweenPropType::X:
        g->setX(value.x);
        break;

    case TweenPropType::Y:
        g->setY(value.y);
        break;

    case TweenPropType::Position:
        g->setPosition(value.x, value.y);
        break;

    case TweenPropType::Width:
        g->setWidth(value.x);
        break;

    case TweenPropType::Height:
        g->setHeight(value.y);
        break;

    case TweenPropType::Size:
        g->setSize(value.x, value.y);
        break;

    case TweenPropType::ScaleX:
        g->setScaleX(value.x);
        break;

    case TweenPropType::ScaleY:
        g->setScaleY(value.y);
        break;

    case TweenPropType::Scale:
        g->setScale(value.x, value.y);
        break;

    case TweenPropType::Rotation:
        g->setRotation(value.x);
        break;

    case TweenPropType::Alpha:
        g->setAlpha(value.x);
        break;

    case TweenPropType::Progress:
        g->as<GProgressBar>()->setValue(value.d);
        break;
    }
}

void TweenPropTypeUtils::setProps(cocos2d::Node * target, TweenPropType propType, const TweenValue & value)
{
    GObject* g = dynamic_cast<GObject*>(target);
    if (g == nullptr)
        return;

    switch (propType)
    {
    case TweenPropType::X:
        g->setX(value.x);
        break;

    case TweenPropType::Y:
        g->setY(value.y);
        break;

    case TweenPropType::Position:
        g->setPosition(value.x, value.y);
        break;

    case TweenPropType::Width:
        g->setWidth(value.x);
        break;

    case TweenPropType::Height:
        g->setHeight(value.y);
        break;

    case TweenPropType::Size:
        g->setSize(value.x, value.y);
        break;

    case TweenPropType::ScaleX:
        g->setScaleX(value.x);
        break;

    case TweenPropType::ScaleY:
        g->setScaleY(value.y);
        break;

    case TweenPropType::Scale:
        g->setScale(value.x, value.y);
        break;

    case TweenPropType::Rotation:
        g->setRotation(value.x);
        break;

    case TweenPropType::Alpha:
        g->setAlpha(value.x);
        break;

    case TweenPropType::Progress:
        g->as<GProgressBar>()->setValue(value.d);
        break;
    }
}

NS_FGUI_END

