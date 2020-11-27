#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>


class Widget :
{
    Widget();

    // methods to transform the widget

    // methods to manage the widget's children

    void draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const;

private:
    virtual void onDraw(sf::RenderTarget& target, const sf::Transform& transform) const = 0;
    sf::Transform mTransform;
    std::vector<Widget*> mChildren;
};

#endif // WIDGET_H_INCLUDED
