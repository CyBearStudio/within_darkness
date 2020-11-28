#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>


namespace Anchors
{
    enum ID
    {
        UpperLeft,
        Left,
        LowerLeft,
        Down,
        LowerRight,
        Right,
        UpperRight,
        Up,
        Center
    };
}

class Widget
{
    Widget();

    // ... methods to transform the widget

    // ... methods to manage the widget's children

    void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const;
    virtual void setOrigin(Anchors::ID anchor);

private:
    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;
    sf::Transform mTransform;
    Anchors::ID mAnchor;
    std::vector<Widget*> mChildren;
};

#endif // WIDGET_H_INCLUDED
