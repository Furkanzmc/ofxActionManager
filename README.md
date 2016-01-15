# ofxActionManager

ofxActionManager is a port of the action system used by [Cocos2dx](https://github.com/cocos2d/cocos2d-x).
The usage is pretty much the same as Cocos2dx. The only difference is you need to inherit `ActionTarget`, or just use it directly for Actions.
You can read about actions [here](http://www.cocos2d-x.org/wiki/Actions)

```C++
void ofApp::update()
{
    const float delta = ofGetLastFrameTime();
    ActionManager::getInstance()->update(delta);
}

void ofApp::draw()
{
    ofCircle(target.getPositon(), 20);
}

void ofApp::mouseReleased(int x, int y, int button)
{
    auto seq = Sequence::create(EaseBounceOut::create(MoveTo::create(1, ofVec2f(x, y))), CallFunc::create([]() {
            std::cout << "Hey Sequence!\n";
        }), nullptr);
    m_Target.runAction(seq);
}
```

# Available Actions in ofxActionManager

## Interval Actions

- [x] Sequence
- [ ] Repeat
- [ ] RepeatForever
- [ ] Spawn
- [ ] RotateTo
- [ ] RotateBy
- [x] MoveBy
- [x] MoveTo
- [ ] SkewTo
- [ ] SkewBy
- [ ] JumpBy
- [ ] JumpTo
- [x] BezierBy
- [x] BezierTo
- [ ] ScaleTo
- [ ] ScaleBy
- [ ] Blink
- [ ] FadeTo
- [ ] FadeIn
- [ ] FadeOut
- [ ] TintTo
- [ ] TintBy
- [x] DelayTime
- [ ] ReverseTime
- [ ] Animate
- [ ] TargetedAction
- [ ] ActionFloat


## Instant Actions

- [ ] Show
- [ ] Hide
- [ ] ToggleVisibility
- [ ] RemoveSelf
- [ ] FlipX
- [ ] FlipY
- [ ] Place
- [x] CallFunc
- [x] CallFuncN

## Easing Actions

- [x] EaseExponentialInOut
- [x] EaseExponentialOut
- [x] EaseIn
- [x] EaseInOut
- [x] EaseOut
- [x] EaseQuadratic
- [x] EaseQuartic
- [x] EaseQuintic
- [x] EaseSineIn
- [x] EaseSineInOut
- [x] EaseSineOut
- [x] EaseBack
- [x] EaseBezierAction
- [x] EaseBounce
- [x] EaseCircle
- [x] EaseCubic
- [x] EaseElastic
- [x] EaseExponentialIn
