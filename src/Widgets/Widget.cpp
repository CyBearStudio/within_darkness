#include "Widgets/Widget.h"


Widget::Widget() : mTransform(), mAnchor(Anchors::Default)
{
    
}

void Widget::draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const
{
    // combine the parent transform with the widget's one
    sf::Transform combinedTransform = parentTransform * mTransform;

    // let the widget draw itself
    onDraw(target, combinedTransform);

    // draw its children
    for (std::size_t i = 0; i < mChildren.size(); ++i)
    {
        mChildren[i]->draw(target, combinedTransform);
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

void Widget::setAnchor(Uint32 anchor) 
{
    mAnchor = anchor;
}

void Widget::onUpdate() 
{
    // nothing here
}
