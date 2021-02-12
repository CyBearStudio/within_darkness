#include "Widgets/VBoxLayout.h"


VBoxLayout::VBoxLayout(float offset, Anchors::Flags anchor) : Widget(anchor), mOffset(offset)
{
}

sf::FloatRect VBoxLayout::getBoundingRect() const 
{
    sf::FloatRect boundingRect(); // creating FloatRect object to return

    if (!mChildren.empty())
    {
        boundingRect = mChildren[0]->getBoundingRect(); // starting with first widget

        for (int i = 1; i < mChildren.size(); ++i)
        {
            sf::FloatRect rect = mChildren[i]->getBoundingRect();

            // if peeking above bounding rect
            if (rect.top < boundingRect.top)
            {
                boundingRect.height += boundingRect.top - rect.top;
                boundingRect.top = rect.top;
            }

            // if peeking on the left of bounding rect
            if (rect.left < boundingRect.left)
            {
                boundingRect.width += boundingRect.left - rect.left;
                boundingRect.left = rect.left;
            }

            // if peeking under of bounding rect
            if (rect.top + rect.height > boundingRect.top + boundingRect.height)
            {
                boundingRect.height = rect.top + rect.height - boundingRect.top;
            }

            // if peeking under of bounding rect
            if (rect.top + rect.height > boundingRect.top + boundingRect.height)
            {
                boundingRect.height = rect.top + rect.height - boundingRect.top;
            }
        }
    }

    return boundingRect;
}

void VBoxLayout::setOffset(float offset) 
{
    if (offset != mOffset)
    {
        // set new offset
        mOffset = offset;

        // update children transform
        updateTransform();
    }
}

void VBoxLayout::onDraw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    // nothing here
}

void VBoxLayout::onUpdateTransform() 
{
    
}
