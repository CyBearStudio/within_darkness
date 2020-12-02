#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>


namespace Anchors
{
    enum Flags
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

class Widget : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    Widget();

    // ... methods to manage the widget's children
    
    void update();
    void setAnchor(Anchors::Flags anchor);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual void onUpdate();
    Anchors::Flags mAnchor;
    std::vector<Widget*> mChildren;
};

#endif // WIDGET_H_INCLUDED
