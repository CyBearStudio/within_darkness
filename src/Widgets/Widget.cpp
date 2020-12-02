#include "Widgets/Widget.h"


Widget::Widget() : Transformable(), Drawable(), mAnchor(Anchors::Default)
{
    
}

void Widget::attachChild(Widget* child) 
{
    // adding child to children
    mChildren.insert(child);

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
    return sf::Rect();
}

void Widget::onUpdate() 
{
    // nothing here
}

void Widget::tranformChildren() 
{
    // nothing here
}
