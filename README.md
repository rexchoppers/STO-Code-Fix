
# STO Code Fix

## Tweaks done
- Adjusted code + logic for readibility and debugging
- Increase the screen sensitivity by adjusting the 5th parameter in `TouchScreen ts = TouchScreen(XP, YP, XM, YM, 100);` from `300` to `100`
- Reduced loop delay to from `500ms` to `50ms` for loop to capture presses quicker (This is edited in the `delay(50);` function)

## Notes
- Make sure the power source is procuding at least 4.2v (Tested on Mac)