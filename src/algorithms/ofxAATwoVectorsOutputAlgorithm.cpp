/*
 * Copyright (C) 2019 Leo Zimmerman [http://www.leozimmerman.com.ar]
 *
 * ofxAudioAnalyzer is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License as published by the Free
 * Software Foundation (FSF), either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the Affero GNU General Public License
 * version 3 along with this program.  If not, see http://www.gnu.org/licenses/
 *
 * ---------------------------------------------------------------
 *
 * This project uses Essentia, copyrighted by Music Technology Group - Universitat Pompeu Fabra
 * using GNU Affero General Public License.
 * See http://essentia.upf.edu for documentation.
 *
 */

#include "ofxAATwoVectorsOutputAlgorithm.h"

ofxAATwoVectorsOutputAlgorithm::ofxAATwoVectorsOutputAlgorithm(ofxaa::AlgorithmType algorithmType, int samplerate, int framesize, int outputSize_1, int outputSize_2) :  ofxAAOneVectorOutputAlgorithm(algorithmType, samplerate, framesize, outputSize_1) {
    assignSecondOutpuValuesSize(outputSize_2, 0.0);
}

void ofxAATwoVectorsOutputAlgorithm::castToFloat(){
    ofxAAOneVectorOutputAlgorithm::castToFloat();
    castValues(realValues_2, floatValues_2);
}

void ofxAATwoVectorsOutputAlgorithm::assignSecondOutpuValuesSize(int size, int val){
    realValues_2.assign(size, val);
    floatValues_2.assign(size, val);
    smoothedFloatValues_2.assign(size, val);
}
