/*
 * Camara Lucida
 * www.camara-lucida.com.ar
 *
 * Copyright (C) 2011  Christian Parsons
 * www.chparsons.com.ar
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "cmlOpticalDevice.h"

namespace cml
{
    class Kinect : public OpticalDevice
    {
        public:

            Kinect(const OpticalDevice::Config& config, int xoff); 

            ~Kinect();

            void unproject( 
                    int x2d, int y2d, float z, float *x, float *y);
            void unproject(
                    int x2d, int y2d, float z, ofVec2f *p2);
            ofVec2f unproject(
                    int x2d, int y2d, float z);

            void project(const ofVec3f& p3, float *x, float *y);
            ofVec2f project(const ofVec3f& p3);

            float z_mts(uint16_t raw_depth);
            float z_mts(uint16_t *raw_depth_pix, int _x, int _y);

            void raw_depth_to_p3( 
                    uint16_t *raw_depth_pix, 
                    int _x, int _y, ofVec3f *p3);
            
            ofVec3f raw_depth_to_p3( 
                    uint16_t *raw_depth_pix, 
                    int _x, int _y);

            void raw_depth_to_p3( 
                    uint16_t raw_depth, 
                    int _x, int _y, ofVec3f *p3); 

            ofVec3f raw_depth_to_p3( 
                    uint16_t raw_depth, 
                    int _x, int _y);

            void change_xoff( int val );
            int get_xoff();

        private:

            float k1, k2, k3, k4;

            float *_zlut;
            int xoff;

            float z_raw_to_mts(uint16_t raw_depth); 
    };
};


