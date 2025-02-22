#ifndef DISPLAY_PROGRESS_HPP
#define DISPLAY_PROGRESS_HPP

#ifdef USE_SFML
void displayProgress();
#else
inline void displayProgress() {} // Empty function when SFML is disabled
#endif

#endif
