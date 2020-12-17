#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <vector>


class Widget;

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

    void anchor(const sf::RenderTarget& target, Widget& widget, Flags flag, float offset = 0.f);
}

class Widget : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
    Widget(Anchors::Flags anchor = Anchors::Default);

private:
    // ... methods to manage the widget's children
    void attachChild(Widget* child);
    void detachChild(Widget* child);

    // ... methods to manage the widget's parents
    void addParent(Widget* parent);
    void removeParent(Widget* parent);
    
public:
    // ... methods to manage parenting
    static void make_parent(Widget* parent, Widget* child);
    static void revoke_parent(Widget* parent, Widget* child);

    void update();
    void updateTransform();
    void setAnchor(Anchors::Flags anchor);
    virtual sf::FloatRect getBoundingRect() const;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual void onUpdate();
    virtual void onUpdateTransform();
    Anchors::Flags mAnchor;
    std::vector<Widget*> mParents;
    std::vector<Widget*> mChildren;
};

#endif // WIDGET_H_INCLUDED
