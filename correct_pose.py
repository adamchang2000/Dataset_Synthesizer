import os
import pandas as pd
import numpy as np

pose_path = r'C:\Users\OpenARK\Desktop\adam\camera_test_fixed_markers_cleaned.csv'
cleaned_pose_path = pose_path[:pose_path.rfind(".csv")] + "_cleaned.csv"

poses = pd.read_csv(pose_path)

rotations = poses[["camera_Rotation_X", "camera_Rotation_Y", "camera_Rotation_Z", "camera_Rotation_W"]]
rotations = np.array(rotations)
            
