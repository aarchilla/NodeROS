//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the safe_landing_planner package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __safe_landing_planner__WAYPOINTGENERATORNODECONFIG_H__
#define __safe_landing_planner__WAYPOINTGENERATORNODECONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace safe_landing_planner
{
  class WaypointGeneratorNodeConfigStatics;

  class WaypointGeneratorNodeConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }

      virtual void clamp(WaypointGeneratorNodeConfig &config, const WaypointGeneratorNodeConfig &max, const WaypointGeneratorNodeConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const WaypointGeneratorNodeConfig &config1, const WaypointGeneratorNodeConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, WaypointGeneratorNodeConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const WaypointGeneratorNodeConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, WaypointGeneratorNodeConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const WaypointGeneratorNodeConfig &config) const = 0;
      virtual void getValue(const WaypointGeneratorNodeConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T WaypointGeneratorNodeConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (WaypointGeneratorNodeConfig::* field);

      virtual void clamp(WaypointGeneratorNodeConfig &config, const WaypointGeneratorNodeConfig &max, const WaypointGeneratorNodeConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const WaypointGeneratorNodeConfig &config1, const WaypointGeneratorNodeConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, WaypointGeneratorNodeConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const WaypointGeneratorNodeConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, WaypointGeneratorNodeConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const WaypointGeneratorNodeConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const WaypointGeneratorNodeConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, WaypointGeneratorNodeConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, WaypointGeneratorNodeConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<WaypointGeneratorNodeConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(WaypointGeneratorNodeConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("landing_radius"==(*_i)->name){landing_radius = boost::any_cast<double>(val);}
        if("can_land_thr"==(*_i)->name){can_land_thr = boost::any_cast<double>(val);}
        if("loiter_height"==(*_i)->name){loiter_height = boost::any_cast<double>(val);}
        if("smoothing_land_cell"==(*_i)->name){smoothing_land_cell = boost::any_cast<int>(val);}
        if("beta"==(*_i)->name){beta = boost::any_cast<double>(val);}
        if("vertical_range_error"==(*_i)->name){vertical_range_error = boost::any_cast<double>(val);}
        if("spiral_width"==(*_i)->name){spiral_width = boost::any_cast<double>(val);}
      }
    }

    double landing_radius;
double can_land_thr;
double loiter_height;
int smoothing_land_cell;
double beta;
double vertical_range_error;
double spiral_width;

    bool state;
    std::string name;

    
}groups;



//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double landing_radius;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double can_land_thr;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double loiter_height;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int smoothing_land_cell;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double beta;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double vertical_range_error;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double spiral_width;
//#line 228 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("WaypointGeneratorNodeConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const WaypointGeneratorNodeConfig &__max__ = __getMax__();
      const WaypointGeneratorNodeConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const WaypointGeneratorNodeConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const WaypointGeneratorNodeConfig &__getDefault__();
    static const WaypointGeneratorNodeConfig &__getMax__();
    static const WaypointGeneratorNodeConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const WaypointGeneratorNodeConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void WaypointGeneratorNodeConfig::ParamDescription<std::string>::clamp(WaypointGeneratorNodeConfig &config, const WaypointGeneratorNodeConfig &max, const WaypointGeneratorNodeConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class WaypointGeneratorNodeConfigStatics
  {
    friend class WaypointGeneratorNodeConfig;

    WaypointGeneratorNodeConfigStatics()
    {
WaypointGeneratorNodeConfig::GroupDescription<WaypointGeneratorNodeConfig::DEFAULT, WaypointGeneratorNodeConfig> Default("Default", "", 0, 0, true, &WaypointGeneratorNodeConfig::groups);
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.landing_radius = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.landing_radius = 10.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.landing_radius = 2.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("landing_radius", "double", 0, "Radius around a land waypoint when starting to block/continue landing", "", &WaypointGeneratorNodeConfig::landing_radius)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("landing_radius", "double", 0, "Radius around a land waypoint when starting to block/continue landing", "", &WaypointGeneratorNodeConfig::landing_radius)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.can_land_thr = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.can_land_thr = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.can_land_thr = 0.4;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("can_land_thr", "double", 0, "Hysteresis on landable cell", "", &WaypointGeneratorNodeConfig::can_land_thr)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("can_land_thr", "double", 0, "Hysteresis on landable cell", "", &WaypointGeneratorNodeConfig::can_land_thr)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.loiter_height = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.loiter_height = 12.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.loiter_height = 8.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("loiter_height", "double", 0, "Z distance to the pointcloud to start loitering ", "", &WaypointGeneratorNodeConfig::loiter_height)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("loiter_height", "double", 0, "Z distance to the pointcloud to start loitering ", "", &WaypointGeneratorNodeConfig::loiter_height)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.smoothing_land_cell = 0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.smoothing_land_cell = 100;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.smoothing_land_cell = 6;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<int>("smoothing_land_cell", "int", 0, "Kernel size on cell land hysteresis", "", &WaypointGeneratorNodeConfig::smoothing_land_cell)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<int>("smoothing_land_cell", "int", 0, "Kernel size on cell land hysteresis", "", &WaypointGeneratorNodeConfig::smoothing_land_cell)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.beta = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.beta = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.beta = 0.9;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("beta", "double", 0, "History paramter on land decision per cell", "", &WaypointGeneratorNodeConfig::beta)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("beta", "double", 0, "History paramter on land decision per cell", "", &WaypointGeneratorNodeConfig::beta)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.vertical_range_error = 0.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.vertical_range_error = 4.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.vertical_range_error = 0.5;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("vertical_range_error", "double", 0, "If the different to loiter_height is greater than this paramter, the vehicle adjust altitude before taking decision", "", &WaypointGeneratorNodeConfig::vertical_range_error)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("vertical_range_error", "double", 0, "If the different to loiter_height is greater than this paramter, the vehicle adjust altitude before taking decision", "", &WaypointGeneratorNodeConfig::vertical_range_error)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.spiral_width = 1.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.spiral_width = 10.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.spiral_width = 2.0;
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("spiral_width", "double", 0, "Factor to increase squared spiral width", "", &WaypointGeneratorNodeConfig::spiral_width)));
//#line 290 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr(new WaypointGeneratorNodeConfig::ParamDescription<double>("spiral_width", "double", 0, "Factor to increase squared spiral width", "", &WaypointGeneratorNodeConfig::spiral_width)));
//#line 245 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 245 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(WaypointGeneratorNodeConfig::AbstractGroupDescriptionConstPtr(new WaypointGeneratorNodeConfig::GroupDescription<WaypointGeneratorNodeConfig::DEFAULT, WaypointGeneratorNodeConfig>(Default)));
//#line 366 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<WaypointGeneratorNodeConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<WaypointGeneratorNodeConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    WaypointGeneratorNodeConfig __max__;
    WaypointGeneratorNodeConfig __min__;
    WaypointGeneratorNodeConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const WaypointGeneratorNodeConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static WaypointGeneratorNodeConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &WaypointGeneratorNodeConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const WaypointGeneratorNodeConfig &WaypointGeneratorNodeConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const WaypointGeneratorNodeConfig &WaypointGeneratorNodeConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const WaypointGeneratorNodeConfig &WaypointGeneratorNodeConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<WaypointGeneratorNodeConfig::AbstractParamDescriptionConstPtr> &WaypointGeneratorNodeConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<WaypointGeneratorNodeConfig::AbstractGroupDescriptionConstPtr> &WaypointGeneratorNodeConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const WaypointGeneratorNodeConfigStatics *WaypointGeneratorNodeConfig::__get_statics__()
  {
    const static WaypointGeneratorNodeConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = WaypointGeneratorNodeConfigStatics::get_instance();

    return statics;
  }


}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __WAYPOINTGENERATORNODERECONFIGURATOR_H__
