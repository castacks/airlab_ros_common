#ifndef __AIRLAB_ROS_COMMON_ROS_COMMON_HPP__
#define __AIRLAB_ROS_COMMON_ROS_COMMON_HPP__

// ROS.
#include <ros/ros.h>

// Macros.
#define GET_PARAM(type, name, node_handle) \
    type name; \
    if ( !node_handle.getParam(#name, name) ) { \
        ROS_ERROR_STREAM("No " << #name << " parameter found. "); \
        return EXIT_FAILURE; \
    }

#define GET_PARAM_DEFAULT(type, name, default_value, node_handle) \
    type name; \
    if ( !node_handle.param<type>( #name, name, default_value ) ) { \
        ROS_WARN_STREAM("No " << #name << " parameter found. Default value " << default_value << " used. "); \
    }

#endif // __AIRLAB_ROS_COMMON_ROS_COMMON_HPP__
