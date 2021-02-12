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

void Widget::addParent(Widget* parent) 
{
    // adding parent to parents
    mParents.push_back(child);

    // updating transforms
    parent->updateTransform();
}

void Widget::removeParent(Widget* parent) 
{
    // finding parent if in parents and removing all its occurences
    for (std::size_t i = 0; i < mParents.size(); ++i)
    {
        if(mParents[i] == child)
        {
            mParents.erase(mParents.begin() + i);
        }
    }

    // updating transforms
    parent->updateTransform();
}

void Widget::make_parent(Widget* parent, Widget* child) 
{
    if (parent != nullptr)
    {
        child->addParent(parent);
    }

    if (child != nullptr)
    {
        parent->attachChild(child);
    }
}

void Widget::revoke_parent(Widget* parent, Widget* child) 
{
    if (parent != nullptr)
    {
        child->removeParent(parent);
    }

    if (child != nullptr)
    {
        parent->detachChild(child);
    }
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

    // update parents transforms
    for (std::size_t i = 0; i < mParents.size(); ++i)
    {
        mParents[i]->updateTransform();
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

sf::Vector2f Widget::getGlobalPosition(Widget* parent) 
{
    Widget* firstParent = getFirstParentOnChain(parent);

    if (firstParent != nullptr)
    {
        return firstParent->getGlobalPosition() + getPosition();
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

Widget* Widget::getFirstParentOnChain(Widget* parent) 
{
    if (parent != nullptr)
    {
        for (int i = 0; i < mParents.size(); ++i)
        {
            if (mParents[i] == parent || mParents[i]->getFirstParentOnChain() != nullptr)
            {
                return mParents[i];
            }
        }
    }

    return nullptr;
}
