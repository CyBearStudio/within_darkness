#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>


namespace Anchors
{
    enum
    {
        Left = 1 << 0,
        Right = 1 << 1,
        CenterX = 1 << 2,
        Up = 1 << 3,
        Down = 1 << 4,
        CenterY = 1 << 5,

        UpLeft = Left | Up,
        UpRight = Right | Up,
        UpCenter = CenterX | Up,
        DownLeft = Left | Down,
        DownRight = Right | Down,
        DownCenter = CenterX | Down,
        CenterLeft = Left | CenterY,
        CenterRight = Right | CenterY,
        Center = CenterX | CenterY,

        Default = UpLeft
    };
}

class Widget
{
    Widget();

    // ... methods to transform the widget

    // ... methods to manage the widget's children

    void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const;
    void setAnchor(Uint32 anchor);

private:
    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;
    sf::Transform mTransform;
    Uint32 mAnchor;
    std::vector<Widget*> mChildren;
};

#endif // WIDGET_H_INCLUDED
