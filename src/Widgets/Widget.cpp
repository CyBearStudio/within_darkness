#include "Widgets/Widget.h"


Widget::Widget() : Transformable(), Drawable(), mAnchor(Anchors::Default)
{
    
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

void Widget::setAnchor(Anchors::ID anchor) 
{
    mAnchor = anchor;
}

void Widget::onUpdate() 
{
    // nothing here
}
