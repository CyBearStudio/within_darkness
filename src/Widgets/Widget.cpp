#include "Widgets/Widget.h"

#include <SFML/System/Vector2.hpp>


namespace Anchors
{
    void anchor(const sf::RenderTarget& target, Widget& widget, Flags flag, float offset) 
    {
        // defining useful values
        sf::Vector2f targetSize(target.getSize());
        sf::Vector2f pos;

        // determine x position
        switch (flag & (Left | Right | CenterX))
        {
            case Left:
                pos.x = 0.f + offset;
                break;

            case Right:
                pos.x = targetSize.x - offset;
                break;

            case CenterX:
                pos.x = targetSize.x / 2;
                break;

            default:
                pos.x = 0.f;
                break;
        }

        // determine y position
        switch (flag & (Up | Down | CenterY))
        {
            case Up:
                pos.y = 0.f + offset;
                break;

            case Down:
                pos.y = targetSize.y - offset;
                break;

            case CenterY:
                pos.y = targetSize.y / 2;
                break;

            default:
                pos.y = 0.f;
                break;
        }

        // apply position to widget
        widget.setPosition(pos);
    }
}

Widget::Widget(Anchors::Flags anchor) : Transformable(), Drawable(), mAnchor(anchor)
{
    
}

void Widget::attachChild(Widget* child) 
{
    // adding child to children
    mChildren.push_back(child);

    // updating transforms
    updateTransform();
}

void Widget::detachChild(Widget* child) 
{
    // finding child if in children and removing all its occurences
    for (std::size_t i = 0; i < mChildren.size(); ++i)
    {
        if(mChildren[i] == child)
        {
            mChildren.erase(mChildren.begin() + i);
        }
    }

    // updating transforms
    updateTransform();
}

Widget* Widget::getParent() 
{
    return mParent;
}

void Widget::setParent(Widget* parent) 
{
    mParent = parent;
}

void Widget::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // combine the parent transform with the widget's one
    states.transform *= getTransform();

    // let the widget draw itself
    onDraw(target, states);

    // draw its children
    for (std::size_t i = 0; i < mChildren.size(); ++i)
    {
        mChildren[i]->draw(target, states);
    }
}

void Widget::update() 
{
    // let the widget update itself
    onUpdate();

    // update its children
    for (std::size_t i = 0; i < mChildren.size(); ++i)
    {
        mChildren[i]->update();
    }
}

void Widget::updateTransform() 
{
    // update widget transform
    onUpdateTransform();

    // update parent transforms
    if(mParent != nullptr){
        mParent->updateTransform();
    }
    
}

void Widget::setAnchor(Anchors::Flags anchor) 
{
    if (anchor != mAnchor)
    {
        // set new anchor
        mAnchor = anchor;

        // update transforms
        updateTransform();
    }
}

sf::FloatRect Widget::getBoundingRect() const
{
    return sf::FloatRect();
}

sf::Vector2f Widget::getGlobalPosition() 
{
    if (mParent != nullptr)
    {
        return mParent->getGlobalPosition() + getPosition();
    }

    return getPosition();
}

void Widget::onUpdate() 
{
    // nothing here
}

void Widget::onUpdateTransform() 
{
    // nothing here
}
