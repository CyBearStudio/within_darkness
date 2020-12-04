#include "Widgets/Widget.h"

#include <SFML/System/Vector2.hpp>


namespace Anchors
{
    void anchor(const sf::RenderTarget& target, Widget& widget, Flags flag, float offset = 0.f) 
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

Widget::Widget() : Transformable(), Drawable(), mAnchor(Anchors::Default)
{
    
}

void Widget::attachChild(Widget* child) 
{
    // adding child to children
    mChildren.push_back(child);

    // updating children transforms
    transformChildren();
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

void Widget::setAnchor(Anchors::Flags anchor) 
{
    if (anchor != mAnchor)
    {
        // set new anchor
        mAnchor = anchor;

        // update children transform
        transformChildren();
    }
}

sf::FloatRect Widget::getBoundingRect() const
{
    return sf::FloatRect();
}

void Widget::onUpdate() 
{
    // nothing here
}

void Widget::transformChildren() 
{
    // nothing here
}
